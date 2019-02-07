#include "messengerserver.h"
#include <QDebug>
#include "messengersocket.h"
#include <QTextStream>

MessengerServer::MessengerServer(QObject *parent)
    :QTcpServer (parent)
{

}

bool MessengerServer::startServer(quint16 port)
{
    return listen(QHostAddress::Any,port);
}

void MessengerServer::incommingConnection(qintptr handle)
{
    qDebug() << "Nuevo cliente conectado:" << handle;
    auto socket = new MessengerSocket(handle, this);
    mSockets << socket;

    connect(socket, &MessengerSocket::SocketReadyRead, [&](MessengerSocket *S){

        qDebug() << "ReadyRead Executed:" << S ->socketDescriptor();
        QTextStream T(S);
        auto text = T.readAll();

        for (auto i : mSockets)
        {
            QTextStream K(i);
            K << text;
            i->flush();
        }

    });

    connect(socket, &MessengerSocket::SocketStateChanged, [&](MessengerSocket *S, int ST){
        if (ST == QTcpSocket::UnconnectedState)
        {
            qDebug() << "Cliente desconectado:" << S ->socketDescriptor();
            mSockets.removeOne(S);
            for (auto i : mSockets)
            {
                QTextStream K(i);
                K << "El cliente:" << S ->socketDescriptor() << "Se ha desconectado";
                i->flush();
            }
        }
    });
}
