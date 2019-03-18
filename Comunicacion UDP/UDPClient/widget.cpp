#include "widget.h"
#include "ui_widget.h"
#include <QUdpSocket>
#include <QAbstractSocket>

typedef struct _Datagramas
{
    QByteArray data;
    QHostAddress hostAddr;
    quint16 port;
} Datagramas ;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mSocket = new QUdpSocket(this);

    connect(mSocket, SIGNAL(readyRead()), this, SLOT(packet_Received_Signal()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_conectar_pushButton_clicked()
{
    mSocket->bind(QHostAddress::Any,static_cast<quint16>(ui->puerto_spinBox->value()));
}

void Widget::packet_Received_Signal()
{
    if(mSocket->hasPendingDatagrams())
    {
     Datagramas datagrama;
     datagrama.data.resize(static_cast<qint16>(mSocket->pendingDatagramSize()));
     mSocket->readDatagram(datagrama.data.data(), datagrama.data.size(),&datagrama.hostAddr,&datagrama.port);
     QString *String = new QString(datagrama.data.data());
     ui->datos_listWidget->addItem(*String);
     ui->size_spinBox->setValue(datagrama.data.size());
    }
}


void Widget::on_desconectar_pushButton_clicked()
{
    mSocket->close();
}
