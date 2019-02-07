#ifndef VFFWEBSERVER_H
#define VFFWEBSERVER_H


#include <QTcpServer>


class VFFWebServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit VFFWebServer(QObject *parent = nullptr);
    bool startWebServer(int port);
signals:
    void anErrorHasOccurred(QString);
protected:
    void incomingConnection(qintptr socketDescriptor);
private:
    QTcpSocket *mSocket;
};

#endif // VFFWEBSERVER_H
