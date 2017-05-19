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

#ifndef PARSER_H
#define PARSER_H

#include <QByteArray>
#include <QDateTime>
#include <QFileInfo>
#include <QList>
#include <QMap>
#include <QSet>
#include <QString>
#include <QTextStream>
#include <QtGlobal>

#include "map.h"

enum MessageFlag { UNKNOWN = 0, CLEAR, ESS,
                   LEFT, LINK, LOCATION,
                   MOTD, POCKET, QUERY,
                   STATUS, SYSTEM_CHANGE, WARNING
                 };

struct LogInfo
{
    QString channel;
    QFileInfo fileInfo;
    QString pilot;
    QString systemLastMentioned;
    qint64 position;
};

struct MessageInfo
{
    QString originalLine;
    bool indecipherable = false;

    LogInfo* logInfo;

    QString sender;
    QDateTime dateTime;
    QString text;
    QString markedUpText;

    QStringList systems;
    QStringList gates;
    QStringList ships;
    QStringList related;
    QStringList possiblePilots;

    QList<MessageFlag> flags;
};

class Parser : public QObject
{
    Q_OBJECT
public:
    explicit Parser(QObject *parent = 0);
    void setMap(Map& map);
    QList<MessageInfo> fileChanged(const QString& path, int maxEntries = 0, bool initialLoad = false);
    QSet<QString> getLocalChannels();

signals:

    // This class has been backported to QObject inheritance.
    // Maybe I should now look at using signals to fire off the
    // messages in a more timely manner.

public slots:

private:
    QString lastListener;
    QString lastLocalSystem;

    QString ignoreChars;
    QSet<QString> clearWords;
    QSet<QString> ignoreWords;
    QSet<QString> localChannels;
    QSet<QString> locationWords;
    QSet<QString> statusWords;
    QSet<QString> ships;

    QMap<QString, LogInfo> fileMap;
    Map* regionMap;

    void loadSet(QSet<QString>& set, QString& string);
    void identifyObjects(MessageInfo& messageInfo);
    QString systemAbbreviation(const QString& word);
    MessageInfo parseLine(const QString& line);
};

#endif // PARSER_H
