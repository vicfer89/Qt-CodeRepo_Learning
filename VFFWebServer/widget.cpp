#include "widget.h"
#include "ui_widget.h"
#include "vffwebserver.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mWebServer = new VFFWebServer(this);

    ui->port_spinBox->setMaximum(INT_MAX);
    ui->port_spinBox->setMinimum(INT_MIN);
    ui->port_spinBox->setValue(80);

    connect(mWebServer, &VFFWebServer::anErrorHasOccurred, [&](const QString &errorString)
    {
       // QMessageBox::Critical(this, "Error");
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_iniciar_pushButton_clicked()
{
    if(mWebServer->startWebServer(ui->port_spinBox->value()))
    {
        QMessageBox::information(this,"OK","Iniciado");
    }
    else {
        //QMessageBox::Critical(this, "error");
    }
}

void Widget::on_salir_pushButton_2_clicked()
{
    close();
}
