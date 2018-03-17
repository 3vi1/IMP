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
#include <QRegExp>
#include <QSet>
#include <QString>
#include <QTextStream>
#include <QtGlobal>

#include "map.h"
#include "msg.h"

struct ImpWord
{
    QString raw;
    QString prefix;
    int     prefixStart;
    QString actual;
    QString postfix;
    int     postfixStart;
};

class Parser : public QObject
{
    Q_OBJECT
public:
    explicit Parser(uint generation, QObject *parent = 0);
    void setMap(Map& map);
    QList<MessageInfo> fileChanged(const QString& path, int maxEntries = 0, bool initialLoad = false);
    QSet<QString> getLocalChannels();

signals:
    void newMessages(QList<MessageInfo> messageInfoList);


public slots:
    void processLine(const QString& line);    // For the debugging option

private:
    uint    generation = 0;
    LogInfo debugLogInfo;   // logInfo used for debugging messages

    //QRegExp listener = QRegExp("^\\[ (.{19}) \\] ([^>]+) > ([^\\.\\?!]*)(.*)$");
    QRegExp listener = QRegExp("^\\[ (.{19}) \\] ([^>]+) > (.*)$");

    QString lastListener;
    QString lastLocalSystem;

    QString ignoreChars;
    QSet<QString> clearWords;
    QSet<QString> closedWords;
    QSet<QString> ignoreWords;
    QSet<QString> left;
    QSet<QString> localChannels;
    QSet<QString> locationWords;
    QSet<QString> openWords;
    QSet<QString> statusWords;
    QSet<QString> ships;
    QSet<QString> wormholeWords;

    QMap<QString, LogInfo> fileMap;
    Map* regionMap;

    void loadSet(QSet<QString>& set, QString& string);
    QString identifyObjects(MessageInfo& messageInfo, QList<ImpWord>& sentence);
    QString systemAbbreviation(const QString& word);
    QList<MessageInfo> parseLine(const QString& line);
};

#endif // PARSER_H
