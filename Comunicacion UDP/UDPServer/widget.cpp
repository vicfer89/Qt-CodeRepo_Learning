#include "widget.h"
#include "ui_widget.h"
#include <QUdpSocket>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mSocket = new QUdpSocket(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_enviar_pushButton_clicked()
{
    auto datagrama = ui->data_lineEdit->text().toLatin1();
    mSocket->writeDatagram(datagrama,QHostAddress(ui->ip_lineEdit->text()),ui->puerto_spinBox->value());
}
