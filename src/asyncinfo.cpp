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


    // Request the Pilot ID

    QUrl url("https://api.eveonline.com/eve/CharacterID.xml.aspx");
    QUrlQuery query;
    query.addQueryItem("names", pilot->name);
    url.setQuery(query);

    QNetworkRequest request(url);
    reply = manager->get(request);
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),
                this, SLOT(error(QNetworkReply::NetworkError)));
    connect(reply, SIGNAL(finished()),
                this, SLOT(idRetrieved()));

    // Resumes asynchronously in idRetrieved()
}

void AsyncInfo::idRetrieved()
{
    QByteArray b = reply->readAll();
    reply->deleteLater();

    QXmlQuery query;
    query.setFocus(b);
    query.setQuery("//*:row/@characterID/string()");
    QString results;
    query.evaluateTo(&results);

    pilot->id = results.toInt();

    QUrl imageUrl("http://image.eveonline.com/Character/" +
                  QString::number(pilot->id) +
                  "_64.jpg");
    QNetworkRequest request(imageUrl);
    reply = manager->get(request);
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),
                this, SLOT(error(QNetworkReply::NetworkError)));
    connect(reply, SIGNAL(finished()),
                this, SLOT(pixmapRetrieved()));

    // Resumes Asynchronously in pixmapRetrieved()
}

void AsyncInfo::pixmapRetrieved()
{
    QByteArray b = reply->readAll();
    reply->deleteLater();

    pilot->avatar.loadFromData(b);

    pilot->cacheUntil = QDateTime::currentDateTimeUtc().addDays(1);

    emit resultReady(pilot);
    this->deleteLater();
}


void AsyncInfo::error(QNetworkReply::NetworkError err)
{
    // Manage error here.
    qDebug() << "*** In AsyncInfo::error:  " << err;
    this->deleteLater();
}

void AsyncInfo::kosCheck(const QString &reqNames)
{
    QString names = reqNames;
    names.replace('\n',',');
    //qDebug() << "* kosCheck requested for " << names;

    QUrl url("http://kos.cva-eve.org/api/");
    QUrlQuery query;
    query.addQueryItem("c", "json");
    query.addQueryItem("type", "multi");
    query.addQueryItem("q", names);
    url.setQuery(query);

    QNetworkRequest request(url);
    kosReply = manager->get(request);
    /*connect(kosReply, SIGNAL(error(QNetworkReply::NetworkError)),
                this, SLOT(error(QNetworkReply::NetworkError)));*/
    connect(kosReply, SIGNAL(finished()),
                this, SLOT(kosCheckReply()));
}

void AsyncInfo::kosCheckReply()
{
    QByteArray b = kosReply->readAll();
    kosReply->deleteLater();

    qDebug() << "kosCheckReply = " << b;

    QList<KosEntry> entries;
    QJsonDocument jsonResponse = QJsonDocument::fromJson(b);
    QJsonObject jsonObject = jsonResponse.object();
    QJsonArray jsonArray = jsonObject["results"].toArray();

    foreach (const QJsonValue& value, jsonArray) {
        QJsonObject obj = value.toObject();
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

    emit kosResultReady(entries);
    this->deleteLater();
}
