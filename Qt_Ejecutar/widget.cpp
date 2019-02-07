#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Ejecutar_pushButton_clicked()
{
    system(ui->Proceso_lineEdit->text().toStdString().c_str());
}

void Widget::on_Quitar_pushButton_clicked()
{
    close();
}
