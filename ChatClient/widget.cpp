#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mSocket = new QTcpSocket(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_enviar_pushButton_clicked()
{

}

void Widget::on_conectar_pushButton_clicked()
{

}
