#include "vffwebserver.h"
#include <QTcpSocket>
#include <QFile>
#include <QTextStream>

VFFWebServer::VFFWebServer(QObject *parent)
    : QTcpServer (parent)
{
    mSocket = nullptr;
}

bool VFFWebServer::startWebServer(int port)
{
    return listen(QHostAddress::Any, port);
}

void VFFWebServer::incomingConnection(qintptr socketDescriptor)
{
    if(mSocket)
    {
        mSocket->close();
        delete mSocket;
    }

    mSocket = new QTcpSocket(this);
    mSocket->setSocketDescriptor(socketDescriptor);
    QFile htmlFile(":/index.html");
    if(!htmlFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        emit anErrorHasOccurred(htmlFile.errorString());
        return;
    }
    QTextStream xin(&htmlFile);
    mSocket->write(xin.readAll().toLatin1());
    mSocket->flush();
    htmlFile.close();
}
