#ifndef EVENTTHREAD_H
#define EVENTTHREAD_H

#include <QDateTime>
#include <QList>
#include <QMap>
#include <QMutex>
#include <QObject>
#include <QThread>
#include <QWaitCondition>

#include "msg.h"     // MessageInfo definition

class EventThread : public QThread
{
    Q_OBJECT
public:
    explicit EventThread(QObject *parent = nullptr);
    ~EventThread();

    void handleEvents(QList<MessageInfo> messages);
    void initParsing();

signals:

public slots:

protected:
    void run() override;

private:

    // Thread Control
    bool abort;
    bool messagesReady;
    QMutex mutex;
    QWaitCondition condition;

    QList<MessageInfo> messages;
    QMap<QString, QDateTime> soundLastPlayed;
};

#endif // EVENTTHREAD_H
