#ifndef LOCALSERVER_H
#define LOCALSERVER_H

#include <QLocalServer>

class QLocalSocket;

class LocalServer : public QLocalServer
{
    Q_OBJECT
public:
    explicit LocalServer(QObject *parent = nullptr);
    ~LocalServer();
    void envia(const QString &msj);

signals:

public slots:
private:
    QLocalSocket *mSocket; // socket para cliente

};

#endif // LOCALSERVER_H
