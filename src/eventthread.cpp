#include "eventthread.h"

EventThread::EventThread(QObject *parent) : QThread(parent)
{
    messagesReady = false;
    abort = false;
}

EventThread::~EventThread()
{
    mutex.lock();
    abort = true;
    condition.wakeOne();
    mutex.unlock();

    wait();
}

void EventThread::run()
{
    forever {
        mutex.lock();
        QList<MessageInfo> messages = this->messages;
        this->messages.clear();
        mutex.unlock();

        foreach (MessageInfo message, messages)
        {

        }

        mutex.lock();
        if (!messagesReady)
            condition.wait(&mutex);
        messagesReady = false;
        mutex.unlock();
    }
}


void EventThread::handleEvents(QList<MessageInfo> messages)
{
    QMutexLocker locker(&mutex);

    this->messages.append(messages);

    if (!isRunning()) {
        start(LowPriority);
    }
    else {
        messagesReady = true;
        condition.wakeOne();
    }
}

/*
void EventThread::initParsing()
{
    chatModel->removeRows(0,chatModel->rowCount());

    if(parser != NULL)
    {
        parser->deleteLater();
    }
    parser = new Parser(++parserGeneration, this);
    parser->setMap(*regionMap);
    connect(parser, &Parser::newMessages, this, &MainWindow::receiveMessages);

    if(lc != NULL)
    {
        lc->deleteLater();
    }
    lc = new LogCatcher(&options);

    lc->setLogDir(options.getLogPath());
#ifdef USE_FALLBACK_POLLER
    lc->setPollerRefresh(options.getPollerRefresh());
#endif

    connect(lc, &LogCatcher::fileChanged,
            this, &MainWindow::fileChanged);

    // Initialize with last session if not old...
    foreach(QString absoluteFilePath, lc->files())
    {
        if((options.getIntelChannels().contains(shortName(absoluteFilePath)) &&
                options.getInitOldIntel()) ||
            parser->getLocalChannels().contains(shortName(absoluteFilePath)))
        {
            fileChanged(absoluteFilePath);
        }
    }

}
*/
