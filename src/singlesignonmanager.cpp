#include "singlesignonmanager.h"
#include <QMessageBox>

SingleSignOnManager::SingleSignOnManager(QObject *parent) : QTcpServer(parent)
{
    connect( &serverSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(tcpError(QAbstractSocket::SocketError)) );
    connect( &serverSocket, SIGNAL(readyRead()),
             this, SLOT(tcpReady()) );
    serverSocket.setSocketOption(QAbstractSocket::KeepAliveOption, true );
}

SingleSignOnManager::~SingleSignOnManager()
{
    serverSocket.disconnectFromHost();
    serverSocket.waitForDisconnected();
}

void SingleSignOnManager::tcpReady() {
    QByteArray array = serverSocket.read(serverSocket.bytesAvailable());
}

void SingleSignOnManager::tcpError(QAbstractSocket::SocketError )//error)
{
    QMessageBox::warning( (QWidget *)this->parent(), tr("Error"),tr("TCP error: %1").arg(serverSocket.errorString() ) );
}

bool SingleSignOnManager::startListen(int port_no) {
    if( !this->listen( QHostAddress::Any, port_no ) ) {
        QMessageBox::warning( (QWidget *)this->parent(), tr("Error!"), tr("Cannot listen to port %1").arg(port_no) );
        return false;
    }

    return true;
}

void SingleSignOnManager::incomingConnection(int descriptor) {
    if( !serverSocket.setSocketDescriptor( descriptor ) ) {
        QMessageBox::warning( (QWidget *)this->parent(), tr("Error!"), tr("Socket error!") );
        return;
    }
}
