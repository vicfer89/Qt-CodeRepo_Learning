#ifndef LOCALSERVER_H
#define LOCALSERVER_H

#include <QTcpServer>

class QTcpSocket;

class LocalServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit LocalServer(QObject *parent = nullptr);
    ~LocalServer();
    void envia(const QString &msj);

signals:

public slots:
private:
    QTcpSocket *mSocket; // socket para cliente

};

#endif // LOCALSERVER_H
