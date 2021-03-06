#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

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

void Widget::on_pushButton_clicked()
{
    QMessageBox::information(this, "Mensaje", "Hola mundo");
    QMessageBox::warning(this, "Advertencia", "No la liaste mu pardas");
    QMessageBox::critical(this, "Error","La cagaste");
}
