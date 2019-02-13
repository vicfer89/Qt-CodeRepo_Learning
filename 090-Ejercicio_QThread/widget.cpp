#include "widget.h"
#include "ui_widget.h"
#include "vffthread.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);
    ui->dial->setValue(0);
    ui->lcdNumber->display(0);

    mVFFThread1 = new VFFThread(10,this);
    mVFFThread2 = new VFFThread(20,this);
    mVFFThread3 = new VFFThread(30,this);

    connect(mVFFThread1,     &VFFThread::valueUpdated,
            ui->progressBar, &QProgressBar::setValue);

    connect(mVFFThread2, &VFFThread::valueUpdated,
            ui->dial,    &QDial::setValue);

    connect(mVFFThread3,   &VFFThread::valueUpdated,
            ui->lcdNumber, static_cast<void (QLCDNumber::*)(int)>(&QLCDNumber::display));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_iniciar_PushButton_clicked()
{
    mVFFThread1->setCounter(0);
    mVFFThread2->setCounter(0);
    mVFFThread3->setCounter(0);
    mVFFThread1->start();
    mVFFThread2->start();
    mVFFThread3->start();
}

void Widget::on_detener_PushButton_clicked()
{
    mVFFThread1->terminate();
    mVFFThread2->terminate();
    mVFFThread3->terminate();
}

void Widget::on_cerrar_PushButton_clicked()
{
    close();
}

void Widget::on_continuar_PushButton_clicked()
{
    mVFFThread1->start();
    mVFFThread2->start();
    mVFFThread3->start();
}
