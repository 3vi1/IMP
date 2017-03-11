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

#ifndef ASYNCINFO_H
#define ASYNCINFO_H

#include <QDateTime>
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QPixmap>
#include <QStringList>

struct PilotEntry
{
    QString name;
    int id;
    QPixmap avatar;
    //QVector<QPair<int,QString>> employmentHistory;
    QDateTime cacheUntil;

    friend QDataStream &operator<<(QDataStream &out, const PilotEntry& pilotEntry)
    {
       out << pilotEntry.name << pilotEntry.id <<
              pilotEntry.avatar << pilotEntry.cacheUntil;
              //pilotEntry.avatar << pilotEntry.employmentHistory << pilotEntry.cacheUntil;
       return out;
    }

    friend  QDataStream &operator>>(QDataStream &in, PilotEntry& pilotEntry)
    {
       in >> pilotEntry.name >> pilotEntry.id >>
               //pilotEntry.avatar >> pilotEntry.employmentHistory >>
               pilotEntry.avatar >>
               pilotEntry.cacheUntil;
       return in;
    }
};

struct KosPilot
{
    int     id;
    QString name;
    QString icon;
    bool    kos;
    int     eveId;
};

struct KosCorp
{
    int     id;
    QString name;
    QString icon;
    bool    kos;
    int     eveId;
    QString ticker;
    bool    npc;
};

struct KosAlliance
{
    int     id;
    QString name;
    QString icon;
    bool    kos;
    int     eveId;
    QString ticker;
};

struct KosEntry
{
    KosPilot pilot;
    KosCorp corp;
    KosAlliance alliance;
};

class AsyncInfo : public QObject
{
    Q_OBJECT

public:
    PilotEntry* pilot;

    explicit AsyncInfo(QNetworkAccessManager& manager, QObject *parent = 0);

    void cacheAvatar(const QString& name);
    void kosCheck(const QString& names);
    void rblCheck(int id);
    void rblCheck(const QString& name, int id = 0);

signals:
    void resultReady(PilotEntry* pilotEntry);
    void kosResultReady(const QString& name, const QList<KosEntry>& entries);
    void rblResultReady(const QString& name, bool kos);


public slots:
    void idRetrieved();
    void rblIdRetrieved();
    void rblInfoRetrieved();
    void pixmapRetrieved();
    void error(QNetworkReply::NetworkError err);
    void gotKosCheckReply();
    void gotKosCheckCorpReply();

private:
    QNetworkAccessManager* manager;
    QNetworkReply* reply;
    QNetworkReply* kosReply;

    QString checkNames = "";

    void requestId(const QString& name, const char* slot);
    void kosCheck(const QString &reqNames, const char* slot, QString queryType  = "multi");
};

#endif // ASYNCINFO_H
