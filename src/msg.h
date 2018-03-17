#ifndef MSG_H
#define MSG_H

#include <QDateTime>
#include <QFileInfo>
#include <QString>

enum MessageFlag { UNKNOWN = 0,
                   CLEAR, CLOSED,
                   ESS,
                   LEFT, LINK, LOCATION,
                   MOTD, OPEN, POCKET, QUERY,
                   STATUS, SYSTEM_CHANGE,
                   WARNING, WORMHOLE
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
    uint    parserGeneration = 0;
    bool    skipOutput = false;

    QString originalLine;
    bool    indecipherable = false;

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

#endif // MSG_H
