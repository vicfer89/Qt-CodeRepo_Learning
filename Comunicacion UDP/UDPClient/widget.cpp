#include "widget.h"
#include "ui_widget.h"
#include <QUdpSocket>
#include <QAbstractSocket>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mSocket = new QUdpSocket(this);

    connect(mSocket, &QUdpSocket::readyRead, [&]()
    {
       if(mSocket->hasPendingDatagrams()){
        QByteArray datagrama;        
        datagrama.resize(mSocket->pendingDatagramSize());
        mSocket->readDatagram(datagrama.data(), datagrama.size());
        QString *String = new QString(datagrama.data());
        ui->datos_listWidget->addItem(*String);
        ui->size_spinBox->setValue(String->length());
       }
    });

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_conectar_pushButton_clicked()
{
    mSocket->bind(QHostAddress(ui->ip_lineEdit->text()),ui->puerto_spinBox->value());
}
