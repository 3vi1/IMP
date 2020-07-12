#ifndef SINGLESIGNONMANAGER_H
#define SINGLESIGNONMANAGER_H

#include <QObject>
#include <QtNetwork>

class SingleSignOnManager : public QTcpServer
{
    Q_OBJECT
public:
    explicit SingleSignOnManager(QObject *parent = 0);
    ~SingleSignOnManager();
    QTcpSocket serverSocket;

public slots:
    void tcpReady();
    void tcpError(QAbstractSocket::SocketError error);
    bool startListen(int portNo);

protected:
    void incomingConnection(int descriptor);
};

#endif // SINGLESIGNONMANAGER_H
