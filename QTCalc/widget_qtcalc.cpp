#include "widget_qtcalc.h"
#include "ui_widget_qtcalc.h"

Widget_QtCalc::Widget_QtCalc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_QtCalc)
{
    ui->setupUi(this);
}

Widget_QtCalc::~Widget_QtCalc()
{
    delete ui;
}

void Widget_QtCalc::on_pBut_Suma_released()
{
    ui->Number_Resultado->setValue(ui->Number_A->value()+ui->Number_B->value());
}

void Widget_QtCalc::on_pBut_Resta_released()
{
    ui->Number_Resultado->setValue(ui->Number_A->value()-ui->Number_B->value());
}

void Widget_QtCalc::on_pBut_Multiplica_released()
{
    ui->Number_Resultado->setValue(ui->Number_A->value()*ui->Number_B->value());
}

void Widget_QtCalc::on_pBut_Divide_released()
{
    ui->Number_Resultado->setValue(ui->Number_A->value()/ui->Number_B->value());
}

void Widget_QtCalc::on_pushButton_released()
{
    ui->Number_A->setValue(0);
    ui->Number_B->setValue(0);
    ui->Number_Resultado->setValue(0);
}
