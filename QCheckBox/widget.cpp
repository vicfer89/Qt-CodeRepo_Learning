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
    QString msg;
    QStringList Ciudades;
    if(ui->Madrid->isChecked())
    {
        Ciudades << ui->Madrid->text();
    }

    if(ui->Cadiz->isChecked())
    {
        Ciudades << ui->Cadiz->text();
    }

    if(ui->Sevilla->isChecked())
    {
        Ciudades << ui->Sevilla->text();
    }

    if(ui->Granada->isChecked())
    {
        Ciudades << ui->Granada->text();
    }

    msg = Ciudades.join(',');
    msg.insert(0,"Las ciudades seleccionadas son: ");
    QMessageBox::information(this, "Ciudades", msg);
}
