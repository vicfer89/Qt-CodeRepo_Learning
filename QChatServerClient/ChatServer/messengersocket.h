#ifndef MESSENGERSOCKET_H
#define MESSENGERSOCKET_H

#include <QTcpSocket>

class MessengerSocket : public QTcpSocket
{
    Q_OBJECT
public:
    MessengerSocket(qintptr handle, QObject *parent = nullptr);
    ~MessengerSocket();
signals:
    void SocketReadyRead(MessengerSocket*);
    void SocketStateChanged(MessengerSocket*, int);
};

#endif // MESSENGERSOCKET_H
