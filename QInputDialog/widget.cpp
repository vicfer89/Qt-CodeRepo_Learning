#include "widget.h"
#include "ui_widget.h"
#include <QInputDialog>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->Resultado->setText("");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    double n = QInputDialog::getDouble(this, "Entrada", "Ingresar número", 0.000, -25000, 25000, 3);
    ui->Resultado->setText(QString::number(n));
}
