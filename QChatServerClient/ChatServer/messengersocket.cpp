#include "messengersocket.h"

MessengerSocket::MessengerSocket(qintptr handle, QObject *parent)
    : QTcpSocket (parent)
{
    setSocketDescriptor(handle);

    connect(this, &MessengerSocket::readyRead, [&](){
        emit SocketReadyRead(this);
    });

    connect(this, &MessengerSocket::stateChanged, [&](int S){
        emit SocketStateChanged(this, S);
    });
}

MessengerSocket::~MessengerSocket()
{

}
