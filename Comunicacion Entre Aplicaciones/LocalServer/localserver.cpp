#include "localserver.h"
#include <QLocalSocket>

LocalServer::LocalServer(QObject *parent)
    : QLocalServer(parent)
{
    mSocket = nullptr;
    connect(this, &LocalServer::newConnection, [&](){
        mSocket = nextPendingConnection();
    });
}

LocalServer::~LocalServer()
{

}

void LocalServer::envia(const QString &msj)
{
   if(mSocket){
        QTextStream T(mSocket);
        T << msj;
        mSocket->flush();
   }
}
