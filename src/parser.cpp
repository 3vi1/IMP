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
#include "utility.h"

#include <QApplication>
#include <QDebug>
#include <QDir>
#include <QMessageBox>
#include <QTextStream>
#include <QtXmlPatterns/QXmlQuery>

using namespace std;

Parser::Parser(uint generation, QObject *parent) : QObject(parent)
{
    this->generation = generation;
    
    listener.setMinimal(true);

    ignoreChars = "[\\\\_=!@#$%^&\\*,\\.\\[\\]\\(\\)\\{\\}\\?]";   // "\\_=!@#$%^&*,./[](){}?"

    // Load words, channels, and ships from files
    ignoreWords = QSet<QString>::fromList(fromFile("common"));
    clearWords = QSet<QString>::fromList(fromFile("clear"));
    left = QSet<QString>::fromList(fromFile("left"));
    localChannels = QSet<QString>::fromList(fromFile("local"));
    locationWords = QSet<QString>::fromList(fromFile("location"));
    statusWords = QSet<QString>::fromList(fromFile("status"));
    ships = QSet<QString>::fromList(fromFile("ships"));
}

void Parser::setMap(Map &map)
{
    regionMap = &map;
}


QSet<QString> Parser::getLocalChannels()
{
    return localChannels;
}

QList<MessageInfo> Parser::fileChanged(const QString& path, int maxEntries, bool /*initialLoad*/)
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
                systemChange.parserGeneration = generation;
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

        QList<MessageInfo> newMessages = parseLine(lines[i].trimmed().remove(0xfeff));

        // Okay, these aren't really separate user-messages...  they are
        // messages to be processed by main window... clean up later.
        foreach(MessageInfo newMessage, newMessages)
        {
            newMessage.parserGeneration = generation;
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
    }
    fileMap[path].position = input.pos();

    return messageInfoList;
}

QList<MessageInfo> Parser::parseLine(const QString& line)
{
    QList<MessageInfo> messages;
    
    QDateTime dateTime;
    QString sender, text;

    // Does message look valid?
    if (listener.indexIn(line.trimmed()) != -1)
    {
        dateTime = QDateTime::fromString(listener.cap(1), "yyyy.MM.dd HH:mm:ss");
        dateTime.setTimeSpec(Qt::UTC);
        sender = listener.cap(2);
        text = listener.cap(3);
    }
    else
    {
        // Can't make heads or tails of this, return upstream.
        MessageInfo messageInfo;
        messageInfo.originalLine = line;
        messageInfo.indecipherable = true;
        messages.append(messageInfo);
        return messages;
    }


    // Is this a system message?
    if (sender == "EVE System")
    {
        MessageInfo messageInfo;
        messageInfo.originalLine = line;
        messageInfo.dateTime = dateTime;
        messageInfo.dateTime.setTimeSpec(Qt::UTC);
        messageInfo.sender = sender;
        messageInfo.text = text;

        // Test to see if this is a system change message:
        //     EVE System > Channel changed to Local : JEIV-E
        //     EVE-System > Chatkanal geändert zu Lokal: JEIV-E*

        QRegExp sysMsgRegExp("^Ch.*Lo[ck]al ?: (.*)\\*?$");
        sysMsgRegExp.setMinimal(true);
        if (sysMsgRegExp.indexIn(text.trimmed()) != -1)
        {
            //qDebug() << "   is a system change message.";
            messageInfo.systems.append(sysMsgRegExp.cap(1));
            messageInfo.flags.append(MessageFlag::SYSTEM_CHANGE);
            messages.append(messageInfo);
            return messages;
        }

        // Test to see if this is a MOTD message:

        QRegExp motdRegExp("^Channel MOTD: (.*)$");
        if (motdRegExp.indexIn(messageInfo.text.trimmed()) != -1)
        {
            messageInfo.flags.append(MOTD);
            messages.append(messageInfo);
            return messages;
        }

        // Test to see if this is an ESS message:
        QRegExp essRegExp("(.*) is now in proximity of the Encounter Surveillance System$");
        if (essRegExp.indexIn(messageInfo.text.trimmed()) != -1)
        {
            messageInfo.flags.append(ESS);
            messageInfo.related.append(essRegExp.cap(1));
            messages.append(messageInfo);
            return messages;
        }
    }


    // Valid, non-system message.  Deconstruct it into sentences and words.
    QRegExp puncPreExp("^" + ignoreChars + "+");
    QRegExp puncPostExp(ignoreChars + "+$");

    int currentPos = 0,
            nextSpace = 0;
    QList<ImpWord>* impSentence = new QList<ImpWord>;
    QList<QList<ImpWord>> impSentences;

    // Build sentences and their word info.
    while(currentPos <= text.length())
    {
        ImpWord impWord;

        nextSpace = text.indexOf(' ', currentPos+1);
        if(nextSpace == -1)
            nextSpace = text.length();

        if(text[currentPos] == ' ')
        {
            currentPos++;
            continue;
        }

        impWord.raw = text.mid(currentPos, nextSpace-currentPos);
        qDebug() << "Parser::identifyObjects - raw =" << impWord.raw;

        if (puncPostExp.indexIn(impWord.raw) != -1)
            impWord.postfix = puncPostExp.cap();
        else
            impWord.postfix = "";
        impWord.postfixStart = currentPos + impWord.raw.length() - impWord.postfix.length();

        // Only build prefix punctuation, if entire string wasn't punctuation.
        if(impWord.postfix != impWord.raw)
        {
            if (puncPreExp.indexIn(impWord.raw) != -1)
                impWord.prefix = puncPreExp.cap();
            else
                impWord.prefix = "";
        }
        impWord.prefixStart = currentPos;

        qDebug() << "Parser::identifyObjects - prefix =" << impWord.prefix <<
                    ", prefixStart =" << impWord.prefixStart <<
                    ", postfix =" << impWord.postfix <<
                    ", postfixStart =" << impWord.postfixStart;

        impWord.actual = impWord.raw.mid(impWord.prefix.length(),
                                  impWord.raw.length()-impWord.postfix.length());

        qDebug() << "Parser::identifyObjects - actual =" << impWord.actual;

        currentPos = nextSpace + 1;
        impSentence->append(impWord);

        if(nextSpace >= text.length())
            impSentences.append(*impSentence);
        else if(impWord.postfix.endsWith('.') ||
                impWord.postfix.endsWith('!') ||
                impWord.postfix.endsWith('?'))
        {
            impSentences.append(*impSentence);
            delete impSentence;
            impSentence = new QList<ImpWord>;
        }
    }
    delete impSentence;
    
    // Now process each sentence in the message and return a message for each.

    QString markedUpText = "";
    foreach(QList<ImpWord> s, impSentences)
    {
        qDebug() << "impSentence:";
        foreach (ImpWord iw, s) {
            qDebug() << '\t' << iw.prefix << iw.actual << iw.postfix;
        }

        MessageInfo messageInfo;
        messageInfo.originalLine = line;
        messageInfo.dateTime = dateTime;
        messageInfo.dateTime.setTimeSpec(Qt::UTC);
        messageInfo.sender = sender;
        messageInfo.text = text;
        messageInfo.skipOutput = true;

        // Bring in some bison later and dump this simple placeholder
        markedUpText += identifyObjects(messageInfo, s);

        QString endingPunctuation = s[s.count()-1].postfix;
        //qDebug() << "endingPunctuation = " << endingPunctuation;

        if (endingPunctuation.contains('?'))
        {
            if(!messageInfo.flags.contains(MessageFlag::STATUS))
                messageInfo.flags.append(MessageFlag::QUERY);
        }
        else if (messageInfo.flags.count() == 0 && messageInfo.systems.count() > 0
                 && messageInfo.possiblePilots.length() > 0)
        {
            messageInfo.flags.append(MessageFlag::WARNING);
        }

        messages.append(messageInfo);
    }

    messages[messages.count()-1].markedUpText = markedUpText;
    messages[messages.count()-1].skipOutput = false;
    return messages;
}

QString Parser::identifyObjects(MessageInfo& messageInfo, QList<ImpWord> &sentence)
{
    QString markedUpText = "<info>";
    QStringList theseSystems;
    QStringList theseShips;
    QStringList theseGates;

    // New parsing
    qDebug() << "Parser::identifyObjects - Parsing sentence in: " << messageInfo.text;

    for(int i=0; i<sentence.length(); i++)
    {
        bool handled = false;

        QString lowerWord = sentence[i].actual.toLower();
        if (ignoreWords.contains(lowerWord) || sentence[i].actual.length() < 2)
        {
            // Common word to ignore, skip it and go to next word.
            markedUpText += sentence[i].prefix + sentence[i].actual + sentence[i].postfix;
            handled = true;
        }
        else if (statusWords.contains(lowerWord))
        {
            messageInfo.flags.append(MessageFlag::STATUS);
            markedUpText += sentence[i].prefix;
            markedUpText += "<status>";
            markedUpText += sentence[i].actual;
            markedUpText += "<info>";
            markedUpText += sentence[i].postfix;
            handled = true;
        }
        else if (locationWords.contains(lowerWord))
        {
            messageInfo.flags.append(MessageFlag::LOCATION);
            markedUpText += sentence[i].prefix;
            markedUpText += "<location>";
            markedUpText += sentence[i].actual;
            markedUpText += "<info>";
            markedUpText += sentence[i].postfix;
            handled = true;
        }
        else if (clearWords.contains(lowerWord))
        {
            if(i > 0)
            {
                if(sentence[i-1].actual.toLower() == "not")
                {
                    // This isn't a clear message at all.
                    //    "> KBP not clear!"
                    // Fall out and let normal processing light up the system.
                    handled = false;
                }
                else if(sentence[i-1].actual.toLower() != "gate")
                {
                    // We don't want to clear a system if someone says a gate is clear
                    //    "> KBP Dital gate clr!"
                    markedUpText += sentence[i].prefix;
                    handled = true;
                }
                else {
                    messageInfo.flags.append(MessageFlag::CLEAR);
                    markedUpText += sentence[i].prefix;
                    markedUpText += "<clear>";
                    handled = true;
                }
            }
            if(handled)
            {
                markedUpText += sentence[i].actual;
                markedUpText += "<info>";
                markedUpText += sentence[i].postfix;
            }
        }
        else if(ships.contains(lowerWord))
        {
           theseShips.append(sentence[i].actual);
           markedUpText += sentence[i].prefix;
           markedUpText += "<ship>";
           markedUpText += sentence[i].actual;
           markedUpText += "<info>";
           markedUpText += sentence[i].postfix;
           handled = true;
        }
        else if(lowerWord == "pocket")
        {
            messageInfo.flags.append(MessageFlag::POCKET);
            handled = true;
        }
        else if(lowerWord.contains(QRegExp("[^ ]{3,5}://.+")))
        {
            markedUpText += "<a href=\"" + sentence[i].raw + "\">";
            markedUpText += sentence[i].raw;
            markedUpText += "</a>";

            messageInfo.flags.append(MessageFlag::LINK);
            handled = true;
        }

        if(!handled) {
            QString systemName = regionMap->getSystemByAbbreviation(sentence[i].actual.toUpper());

            if(systemName.length() > 0)
            {
                if(i < (sentence.length()-1) && sentence[i+1].actual.toLower() == "gate")
                {
                    if(i < (sentence.length()-2) && sentence[i+2].actual.toLower() == "to")
                    {
                        // "x-x gate to..."
                        theseSystems.append(systemName);
                        markedUpText += sentence[i].prefix;
                        markedUpText += "<gate>";
                        markedUpText += sentence[i].actual;
                        markedUpText += "<info>";
                        markedUpText += sentence[i].postfix;
                    }
                    else {
                        // "...at x-x gate"
                        theseGates.append(systemName);
                        markedUpText += sentence[i].prefix;
                        markedUpText += "<gate>";
                        markedUpText += sentence[i].actual;
                        markedUpText += "<info>";
                        markedUpText += sentence[i].postfix;
                    }
                }
                else if(i > 0 && left.contains(sentence[i-1].actual.toLower()) )
                {
                    // Check to see if it is "left *system*", "from *system*", etc.
                    markedUpText += sentence[i].prefix;
                    markedUpText += "<system>";
                    markedUpText += sentence[i].actual;
                    markedUpText += "<info>";
                    markedUpText += sentence[i].postfix;
                }
                else
                {
                    // System mentioned, not adjacent to word 'gate' or one of
                    // the words indicating they left a system.
                    theseSystems.append(systemName);
                    markedUpText += sentence[i].prefix;
                    markedUpText += "<system>";
                    markedUpText += sentence[i].actual;
                    markedUpText += "<info>";
                    markedUpText += sentence[i].postfix;
                }
            }
            else if(lowerWord.length() >= 2)
            {
                messageInfo.possiblePilots.append(sentence[i].actual);
                markedUpText += "<info>";
                markedUpText += sentence[i].prefix;
                markedUpText += sentence[i].actual;
                markedUpText += sentence[i].postfix;
            }
        }

        if(i < sentence.length())
            markedUpText += " ";
    }

    messageInfo.systems = theseSystems;
    messageInfo.ships = theseShips;
    messageInfo.gates = theseGates;

    return markedUpText;
}
