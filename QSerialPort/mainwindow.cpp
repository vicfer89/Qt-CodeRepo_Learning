#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

static QSerialPort *serial;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    serial = new QSerialPort(this); // Nuevo puerto serie

    ui->setupUi(this);
    serial->setPortName("com4");
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);
    serial->write("Envio informacion por puerto serie");

    connect(serial, SIGNAL(readyRead()),this,SLOT(serialReceived()));

}

MainWindow::~MainWindow()
{
    serial->close();
    delete ui;
}

void MainWindow::serialReceived()
{
    ui->label->setText(serial->readAll());
}
