#include "dialog.h"
#include "ui_dialog.h"
#include "webserver.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    mWebServer = new WebServer(this);
    mWebServer->listen(QHostAddress::Any, 1234);
    connect(mWebServer,SIGNAL(mensajeRecibido(QString)),
           this, SLOT(mensajeRecibido(QString)));

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::mensajeRecibido(const QString &mensaje)
{
    ui->listWidget->addItem(mensaje);
}
