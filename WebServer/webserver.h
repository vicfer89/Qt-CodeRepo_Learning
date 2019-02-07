#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <QWebSocketServer>

class WebServer : public QWebSocketServer
{
    Q_OBJECT
public:
    explicit WebServer(QObject *parent = nullptr);
signals:
    void mensajeRecibido(QString);
public slots:
    void conexionNueva();
    void onMensajeRecibido(const QString &mensaje);
private:
    QWebSocket *mSocket;
};

#endif // WEBSERVER_H
