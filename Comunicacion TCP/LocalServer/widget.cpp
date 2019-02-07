#include "widget.h"
#include "ui_widget.h"
#include "localserver.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mLocalServer = new LocalServer(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_iniciar_pushButton_released()
{
    if(!mLocalServer -> listen(QHostAddress::Any,static_cast<quint16>(ui->puerto_spinBox->value())))
        QMessageBox::critical(this, "Error",mLocalServer->errorString());
    else
        QMessageBox::information(this, "Servidor","Iniciado...");
}

void Widget::on_enviar_pushButton_released()
{
    mLocalServer->envia(ui->msj_lineEdit->text());
}

void Widget::on_salir_pushButton_released()
{
    close();
}
