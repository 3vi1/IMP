/*
 * Imp:  Copyright 2016, 2017 Jesse Litton (imp@eternaldusk.com)
 *
 * This file is part of Imp.
 *
 * Imp is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Imp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Imp.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "asyncinfo.h"
#include "meta.h"

#include <iostream>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QRegExp>
#include <QUrlQuery>
#include <QXmlQuery>


AsyncInfo::AsyncInfo(QNetworkAccessManager& manager, QObject *parent) : QObject(parent)
{
    // QNetworkAccessManager only executes 6 requests at a time, others
    //    will be queued.

    this->manager = &manager;
}

void AsyncInfo::cacheAvatar(const QString& name)
{
    //qDebug() << "Caching avatar for " << name;
    pilot = new PilotEntry;
    pilot->name = name;

    requestId(name, SLOT(idRetrieved()));

    // Resumes asynchronously in idRetrieved()
}

void AsyncInfo::requestId(const QString &name, const char* slot)
{
    qDebug() << "AsyncInfo::requestId() - " << name;

    // Request the Pilot ID
    //QUrl url("https://api.eveonline.com/eve/CharacterID.xml.aspx");
    QUrl url("https://esi.evetech.net/latest/search/");
    QUrlQuery query;
    query.addQueryItem("categories", "character");
    query.addQueryItem("datasource", "tranquility");
    query.addQueryItem("language", "en-us");
    query.addQueryItem("search", name);
    query.addQueryItem("strict", "true");
    url.setQuery(query);

    //qDebug() << "AsyncInfo::requestId() - after query";

    QNetworkRequest request(url);
    request.setRawHeader("User-Agent", meta.agentString.toUtf8());
    QNetworkReply* idReply = manager->get(request);
    connect(idReply, SIGNAL(finished()),
                this, slot);
    connect(idReply, static_cast<void (QNetworkReply::*)(QNetworkReply::NetworkError)>(&QNetworkReply::error),
                this, &AsyncInfo::error);
}

void AsyncInfo::idRetrieved()
{
    QNetworkReply* idReply = qobject_cast<QNetworkReply*>(sender());
    if (!idReply)
        return;

    QByteArray b = idReply->readAll();
    idReply->deleteLater();

//    QXmlQuery query;
//    query.setFocus(b);
    //query.setQuery("//*:row/@characterID/string()");
    QString results;
//    query.evaluateTo(&results);
    QJsonDocument jsonResponse = QJsonDocument::fromJson(b);
    QJsonObject jsonObject = jsonResponse.object();
    QJsonArray jsonArray = jsonObject["character"].toArray();

    if (jsonArray.count() > 0)
        pilot->id = jsonArray[0].toInt();
    else
        pilot->id = 0;

//    pilot->id = results.toInt();

    QUrl imageUrl("https://images.evetech.net/characters/" +
                  QString::number(pilot->id) +
                  "/portrait?size=64");
    QNetworkRequest request(imageUrl);
    request.setRawHeader("User-Agent", meta.agentString.toUtf8());
    QNetworkReply* pixmapReply = manager->get(request);
    connect(pixmapReply, static_cast<void (QNetworkReply::*)(QNetworkReply::NetworkError)>(&QNetworkReply::error),
                this, &AsyncInfo::error);
    connect(pixmapReply, &QNetworkReply::finished,
            this, &AsyncInfo::pixmapRetrieved);

    // Resumes Asynchronously in pixmapRetrieved()
}

void AsyncInfo::pixmapRetrieved()
{
    QNetworkReply *pixmapReply = qobject_cast<QNetworkReply*>(sender());
    if (!pixmapReply)
        return;

    QByteArray b = pixmapReply->readAll();
    pixmapReply->deleteLater();

    pilot->avatar.loadFromData(b);

    pilot->cacheUntil = QDateTime::currentDateTimeUtc().addDays(1);

    emit resultReady(pilot);
    this->deleteLater();
}


void AsyncInfo::error(QNetworkReply::NetworkError err)
{
    // Manage error here.
    qDebug() << "*** In AsyncInfo::error:  " << err;

    if(err == QNetworkReply::UnknownContentError)
    {
        qDebug() << "An unknown error related to the remote content was detected.";
    }
    else
    {
        emit kosCheckFailed(checkNames);
    }
    this->deleteLater();
}

void AsyncInfo::kosCheck(const QString &reqNames)
{
    kosCheck(reqNames, SLOT(gotKosCheckReply()));
}

void AsyncInfo::kosCheck(const QString &reqNames,
                         const char* slot,
                         QString queryType)
{    
    checkNames = reqNames;
    QString names = reqNames;

    int nameCount = 1;
    foreach (QChar c, names)
      if (c == '\n') nameCount++;
    if (nameCount > 1 && queryType == "unit")
        queryType = "multi";

    names.replace('\n',',');
    qDebug() << "* kosCheck requested for " << names;

    QUrl url("https://kos.cva-eve.org/api/");
    QUrlQuery query;
    query.addQueryItem("c", "json");
    query.addQueryItem("type", queryType);
    query.addQueryItem("q", names); //QUrl::toPercentEncoding(names, ","));
    url.setQuery(query);

    qDebug() << "Query = " << url.query();

    QNetworkRequest request(url);
    request.setRawHeader("User-Agent", meta.agentString.toUtf8());
    kosReply = manager->get(request);
    connect(kosReply, static_cast<void (QNetworkReply::*)(QNetworkReply::NetworkError)>(&QNetworkReply::error),
                this, &AsyncInfo::error);
    connect(kosReply, SIGNAL(finished()),
                this, slot);

}

void AsyncInfo::gotKosCheckReply()
{
    QByteArray b = kosReply->readAll();
    kosReply->deleteLater();

    qDebug() << "gotKosCheckReply = " << b;

    if(b.length() == 0)
    {
        emit kosCheckFailed(checkNames);
        this->deleteLater();
        return;
    }

    QList<KosEntry> entries;
    QJsonDocument jsonResponse = QJsonDocument::fromJson(b);
    QJsonObject jsonObject = jsonResponse.object();

    // For unlisted, CVA returns:
    // "{\n  "total": 0,\n  "code": 100,\n  "message": "OK",\n  "results": [\n    \n  ]\n}"

    QJsonArray jsonArray = jsonObject["results"].toArray();

    QStringList names = checkNames.toLower().split('\n');
    foreach (const QJsonValue& value, jsonArray) {

        QJsonObject obj = value.toObject();

        // Move on if this doesn't match one of our *specific* *pilot*s
        if(obj["type"].toString() != "pilot" ||
                !names.contains(obj["label"].toString().toLower()))
        {
            continue;
        }

        KosEntry KosEntry;
        KosEntry.pilot.eveId = obj["eveid"].toInt();
        KosEntry.pilot.icon = obj["icon"].toString();
        KosEntry.pilot.id = obj["id"].toInt();
        KosEntry.pilot.kos = obj["kos"].toBool();
        KosEntry.pilot.name = obj["label"].toString();

        QJsonObject corpObj = obj["corp"].toObject();
        KosEntry.corp.eveId = corpObj["eveid"].toInt();
        KosEntry.corp.icon = corpObj["icon"].toString();
        KosEntry.corp.id = corpObj["id"].toInt();
        KosEntry.corp.kos = corpObj["kos"].toBool();
        KosEntry.corp.name = corpObj["label"].toString();
        KosEntry.corp.npc = corpObj["npc"].toBool();
        KosEntry.corp.ticker = corpObj["ticker"].toString();

        QJsonObject allianceObj = corpObj["alliance"].toObject();
        KosEntry.alliance.eveId = allianceObj["eveid"].toInt();
        KosEntry.alliance.icon = allianceObj["icon"].toString();
        KosEntry.alliance.id = allianceObj["id"].toInt();
        KosEntry.alliance.kos = allianceObj["kos"].toBool();
        KosEntry.alliance.name = allianceObj["label"].toString();
        KosEntry.alliance.ticker = allianceObj["ticker"].toString();

        entries.append(KosEntry);
    }

    emit kosResultReady(checkNames, entries);
    this->deleteLater();
}

void AsyncInfo::rblCheck(const QString& name, int id)
{
    checkNames = name;

    if(id == 0)
    {
        // We don't have the person's ID, so we need to get it.
        requestId(name, SLOT(rblIdRetrieved()));
    }
    else
    {
        rblCheck(id);
    }
}

void AsyncInfo::rblCheck(int id)
{
    qDebug() << "AsyncInfo::rblCheck(" << id << ")";

    // Request the Character Information
    QUrl url("https://api.eveonline.com/eve/CharacterInfo.xml.aspx");
    QUrlQuery query;
    query.addQueryItem("characterID", QString::number(id));
    url.setQuery(query);

    QNetworkRequest request(url);
    request.setRawHeader("User-Agent", meta.agentString.toUtf8());
    QNetworkReply* infoReply = manager->get(request);
    connect(infoReply, static_cast<void (QNetworkReply::*)(QNetworkReply::NetworkError)>(&QNetworkReply::error),
                this, &AsyncInfo::error);
    connect(infoReply, &QNetworkReply::finished,
            this, &AsyncInfo::rblInfoRetrieved);
}

void AsyncInfo::rblIdRetrieved()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    if (!reply)
        return;

    QByteArray b = reply->readAll();
    reply->deleteLater();

    qDebug() << "AsyncInfo::rblIdRetrieved - b = " << b;

    QXmlQuery query;
    query.setFocus(b);
    query.setQuery("//*:row/@characterID/string()");
    QString results;
    query.evaluateTo(&results);

    int id = results.toInt();

    rblCheck(id);
}

void AsyncInfo::rblInfoRetrieved()
{
    //qDebug() << "AsyncInfo::rblInfoRetrieved() - Entered...";

    QNetworkReply* infoReply = qobject_cast<QNetworkReply*>(sender());
    if (!infoReply)
        return;

    QByteArray b = infoReply->readAll();
    infoReply->deleteLater();

    qDebug() << "AsyncInfo::rblInfoRetrieved() - " << b;

    if(b.length() == 0)
    {
        emit kosCheckFailed(checkNames);
        this->deleteLater();
        return;
    }

    QXmlQuery query;
    query.setFocus(b);
    query.setQuery("//*:row/concat(@corporationID,',',@corporationName/string())");
    QStringList results;
    query.evaluateTo(&results);

    m_corpNum = 0;
    foreach(QString result, results)
    {
        m_corpNum++;
        QStringList entry = result.split(',');
        if(entry[0].toInt() > 2000000)
        {
            // Found last PC corp
            qDebug() << "  Last PC corp ID =" << entry[0] << ", corp Name =" << entry[1];
            kosCheck(entry[1], SLOT(gotKosCheckCorpReply()), "corp");
            return;
        }
        else
        {
            qDebug() << "  NPC corp ID =" << entry[0] << ", corp Name =" << entry[1];
        }
    }

    emit rblResultReady(checkNames, false);
    this->deleteLater();
}

void AsyncInfo::gotKosCheckCorpReply()
{
    QNetworkReply* rblReply = qobject_cast<QNetworkReply*>(sender());
    if (!rblReply)
        return;

    QByteArray b = rblReply->readAll();
    rblReply->deleteLater();

    //qDebug() << "AsyncInfo::gotKosCheckCorpReply - b = " << b;

    if(b.length() > 0)
    {
        QJsonDocument jsonResponse = QJsonDocument::fromJson(b);
        QJsonObject jsonObject = jsonResponse.object();
        QJsonArray jsonArray = jsonObject["results"].toArray();

        bool found = false;
        if(jsonArray.count() > 0)
        {
            KosEntry kosEntry;
            foreach (const QJsonValue& value, jsonArray) {
                QJsonObject obj = value.toObject();

                kosEntry.corp.eveId = obj["eveid"].toInt();
                kosEntry.corp.icon = obj["icon"].toString();
                kosEntry.corp.id = obj["id"].toInt();
                kosEntry.corp.kos = obj["kos"].toBool();
                kosEntry.corp.name = obj["label"].toString();
                kosEntry.corp.npc = obj["npc"].toBool();
                kosEntry.corp.ticker = obj["ticker"].toString();

                QJsonObject allianceObj = obj["alliance"].toObject();
                kosEntry.alliance.eveId = allianceObj["eveid"].toInt();
                kosEntry.alliance.icon = allianceObj["icon"].toString();
                kosEntry.alliance.id = allianceObj["id"].toInt();
                kosEntry.alliance.kos = allianceObj["kos"].toBool();
                kosEntry.alliance.name = allianceObj["label"].toString();
                kosEntry.alliance.ticker = allianceObj["ticker"].toString();

                if(kosEntry.corp.name.toLower() == checkNames.toLower())
                {
                    found = true;
                    break;
                }
            }

            if(found)
            {
                emit rblResultReady(checkNames, kosEntry.corp.kos | kosEntry.alliance.kos, m_corpNum);
            }
        }

        if(found == false)
        {
            emit rblResultReady(checkNames, false);
        }
    }
    else
    {
        emit rblResultReady(checkNames, false);
    }
    this->deleteLater();
}
