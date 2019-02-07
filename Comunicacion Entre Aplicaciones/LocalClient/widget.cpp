#include "widget.h"
#include "ui_widget.h"
#include <QLocalSocket>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mSocket = new QLocalSocket(this);

    connect(mSocket, &QLocalSocket::readyRead, [&]()
    {
        QTextStream T(mSocket);
        ui->listWidget->addItem(T.readAll());
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_conectar_pushButton_clicked()
{
    mSocket->connectToServer(ui->servidor_lineEdit->text()); // El nombre ha de ser el mismo que para el cliente
}

void Widget::on_salir_pushButton_clicked()
{
    close();
}
