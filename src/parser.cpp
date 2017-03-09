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

#include "parser.h"
#include "abstract_os.h"

#include <QApplication>
#include <QDebug>
#include <QDir>
#include <QMessageBox>
#include <QRegExp>
#include <QTextStream>
#include <QtXmlPatterns/QXmlQuery>

using namespace std;

Parser::Parser(QObject *parent) : QObject(parent)
{
    ignoreChars = "[\\\\_=!@#$%^&\\*,\\./\\[\\]\\(\\)\\{\\}\\?]";   // "\\_=!@#$%^&*,./[](){}?"

    // Load words, channels, and ships from files
    ignoreWords = QSet<QString>::fromList(fromFile("common"));
    clearWords = QSet<QString>::fromList(fromFile("clear"));
    localChannels = QSet<QString>::fromList(fromFile("local"));
    locationWords = QSet<QString>::fromList(fromFile("location"));
    statusWords = QSet<QString>::fromList(fromFile("status"));
    ships = QSet<QString>::fromList(fromFile("ships"));

}

void Parser::setMap(Map &map)
{
    regionMap = &map;
}

QStringList Parser::fromFile(const QString& fileName)
{
    QStringList stringList;

    QFile file(appFilesPath() + "/dictionaries/" + fileName);

    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(NULL, "Error Opening File", "Could not open file dictionaries/" +
                             fileName + ".");
        QApplication::exit(1);
    }
    else
    {
        QTextStream in(&file);
        QString all = in.readAll();
        stringList = all.split('\n');
        stringList.removeAll("");
    }

    return stringList;
}

QSet<QString> Parser::getLocalChannels()
{
    return localChannels;
}

QList<MessageInfo> Parser::fileChanged(const QString& path, int maxEntries)
{
    QFile file(path);
    QTextStream input(&file);
    input.setCodec("UTF-16");

    QList<MessageInfo> messageInfoList;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(NULL, "Error Opening Log", "Could not read log " +
                             path + ".", QMessageBox::Ok);
        return messageInfoList;
    }

    QList<QString> lines;

    int startLine = 0;
    if(fileMap.contains(path))
    {
        input.seek(fileMap[path].position);
        lines = input.readAll().split("\n");
    }
    else
    {
        qDebug() << "Parser::fileChanged - Adding file " << path;

        QFileInfo fileInfo(file);

        QString baseName = fileInfo.fileName();
        QString channel = baseName.left(baseName.length()-20);
        fileMap.insert(path, LogInfo{channel, fileInfo, "", "", 0}); //logInfo);

        lines = input.readAll().split("\n");

        // Find the system and pilot name
        //  Channel ID:      (('solarsystemid2', 30003763),)
        QRegExp sysIdRegExp("Channel ID: .*, ([0-9]+)\\)");
        QRegExp listenerRegExp("Listener: +([^ ].*)");
        foreach (QString line, lines)
        {
            if (sysIdRegExp.indexIn(line) != -1 && localChannels.contains(channel))
            {
                MessageInfo systemChange;
                systemChange.flags.append(MessageFlag::SYSTEM_CHANGE);
                systemChange.systems.append(regionMap->getSystemById(sysIdRegExp.cap(1)));
                systemChange.text = "System changed to " + systemChange.systems[0];
                systemChange.logInfo = &fileMap[path];
                messageInfoList.append(systemChange);

                qDebug() << "Parser::fileChanged - Setting initial local channel.  " <<
                            sysIdRegExp.cap(1) << " = " << systemChange.systems[0] << ".";
            }
            if (listenerRegExp.indexIn(line) != -1)
            {
                fileMap[path].pilot = listenerRegExp.cap(1);
                break;
            }
        }

        if(maxEntries == 0)
        {
            startLine = 12;
        }
        else
        {
            // This is the first time we're opening this file, and the user specified a
            // maximum number of entries to load.
            startLine = lines.length() - maxEntries - 1;
            startLine = startLine < 12 ? 12 : startLine;
        }
    }

    for (int i=startLine; i<lines.length()-1; i++) {

        MessageInfo newMessage = parseLine(lines[i].trimmed().remove(0xfeff));

        newMessage.logInfo = &fileMap[path];
        if(newMessage.systems.length() > 0)
        {
            newMessage.logInfo->systemLastMentioned = newMessage.systems[0];
        }

        if (!newMessage.indecipherable)
        {
            messageInfoList.append(newMessage);
        }
        else
        {
            qDebug() << "Parser::fileChanged() - Indecipherable message:  " <<
                        fileMap[path].channel << "> " << lines[i] << endl;
        }
    }
    fileMap[path].position = input.pos();

    return messageInfoList;
}

MessageInfo Parser::parseLine(const QString& line)
{
    MessageInfo messageInfo;
    messageInfo.originalLine = line;

    // Get timestamp
    QRegExp listener("^\\[ (.{19}) \\] ([^>]+) > ([^\\.\\?!]*)(.*)$");
    listener.setMinimal(true);
    if (listener.indexIn(line.trimmed()) != -1)
    {
        messageInfo.indecipherable = false;

        QString cap1 = listener.cap(1);
        messageInfo.dateTime = QDateTime::fromString(listener.cap(1), "yyyy.MM.dd HH:mm:ss");
        messageInfo.dateTime.setTimeSpec(Qt::UTC);
        messageInfo.sender = listener.cap(2);

        messageInfo.text = listener.cap(3);

        if (messageInfo.sender == "EVE System")
        {
            //qDebug() << "Parser::parseLine(" << line << ")";

            // Test to see if this is a system change message:
            //     EVE System > Channel changed to Local : JEIV-E

            QRegExp sysMsgRegExp("^Channel changed to .* : (.*)$");
            sysMsgRegExp.setMinimal(true);
            if (sysMsgRegExp.indexIn(messageInfo.text.trimmed()) != -1)
            {
                //qDebug() << "   is a system change message.";
                messageInfo.systems.append(sysMsgRegExp.cap(1));
                messageInfo.flags.append(MessageFlag::SYSTEM_CHANGE);
                return messageInfo;
            }
            else
            {
                //qDebug() << "   is not a system change message.";
            }

            // Test to see if this is a MOTD message:

            QRegExp motdRegExp("^Channel MOTD: (.*)$");
            if (motdRegExp.indexIn(messageInfo.text.trimmed()) != -1)
            {
                messageInfo.flags.append(MOTD);
                return messageInfo;
            }

            // Test to see if this is an ESS message:
            QRegExp essRegExp("(.*) is now in proximity of the Encounter Surveillance System$");
            if (essRegExp.indexIn(messageInfo.text.trimmed()) != -1)
            {
                messageInfo.flags.append(ESS);
                messageInfo.related.append(essRegExp.cap(1));
                return messageInfo;
            }

        }

        // Bring in some bison later and dump this simple placeholder
        identifyObjects(messageInfo);

        QString endingPunctuation = listener.cap(4);
        //qDebug() << "endingPunctuation = " << endingPunctuation;

        if (endingPunctuation.contains('?'))
        {
            messageInfo.flags.append(MessageFlag::QUERY);
        }
        else if (messageInfo.flags.count() == 0 && messageInfo.systems.count() > 0
                 && messageInfo.possiblePilots.length() > 0)
        {
            messageInfo.flags.append(MessageFlag::WARNING);
        }
    }
    else
    {
        messageInfo.indecipherable = true;
    }

    return messageInfo;
}

void Parser::identifyObjects(MessageInfo& messageInfo)
{
    QStringList theseSystems;
    QStringList theseShips;
    QStringList theseGates;

    // Turn any punctuation into whitespace and remove all redundant whitespace.
    // Makes things like "name in XX-XXX...svipul" not get misparsed.
    QString simChat = messageInfo.text;
    simChat = simChat.replace(QRegExp(ignoreChars), " ");
    simChat = simChat.simplified();
    QStringList words = simChat.split(" ");

    QString previousWord = "";
    for (int i = 0; i < words.length(); i++)
    {
        QString lowerWord = words[i].toLower();
        if (ignoreWords.contains(lowerWord) || words[i].length() < 2)
        {
            // Common word to ignore, skip it and go to next word.
        }
        else if (statusWords.contains(lowerWord))
        {
            messageInfo.flags.append(MessageFlag::STATUS);
            messageInfo.flags.append(MessageFlag::QUERY);
        }
        else if (locationWords.contains(lowerWord))
        {
            messageInfo.flags.append(MessageFlag::LOCATION);
        }
        else if (clearWords.contains(lowerWord))
        {
            if(previousWord != "gate")
            {
                // We don't want to clear a system if someone says a gate is clear.
                // "> KBP Dital gate clr!"
                messageInfo.flags.append(MessageFlag::CLEAR);
            }
        }
        else if(ships.contains(lowerWord))
        {
           theseShips.append(words[i]);
        }
        else
        {
            QString systemName = regionMap->getSystemByAbbreviation(words[i].toUpper());

            if(systemName.length() > 0)
            {
                if(i < (words.length()-1) && words[i+1].toLower() == "gate")
                {
                    if(i < (words.length()-2) && words[i+2].toLower() == "to")
                    {
                        // "x-x gate to..."
                        theseSystems.append(systemName);
                    }
                    else {
                        // "...at x-x gate"
                        theseGates.append(systemName);
                    }
                }
                else
                {
                    // System mentioned, not adjacent to word 'gate'
                    theseSystems.append(systemName);
                }
            }
            else if(lowerWord.length() >= 3)
            {
                messageInfo.possiblePilots.append(words[i]);
            }
        }

        previousWord = lowerWord;
    }

    messageInfo.systems = theseSystems;
    messageInfo.ships = theseShips;
    messageInfo.gates = theseGates;
}
