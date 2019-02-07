#include "webserver.h"
#include <QWebSocket>

WebServer::WebServer(QObject *parent)
    : QWebSocketServer("Servidor", QWebSocketServer::NonSecureMode, parent)
{
    mSocket = nullptr;
    connect(this,SIGNAL(newConnection()),
            this, SLOT(conexionNueva()));
}

void WebServer::conexionNueva()
{
    mSocket = nextPendingConnection();
    connect(mSocket,SIGNAL(textMessageReceived(QString)),
            this, SLOT(onMensajeRecibido()));
}

void WebServer::onMensajeRecibido(const QString &mensaje)
{
    emit mensajeRecibido(mensaje);
}
