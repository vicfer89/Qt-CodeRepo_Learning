#include "widget.h"
#include "ui_widget.h"

void cierraAPP()
{
    qApp->closeAllWindows();
}

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(close()));
    //connect(ui->pushButton, &QPushButton::clicked, this, &Widget::cerrarApp); // Sintaxis Alterna
    connect(ui->pushButton, &QPushButton::released, &cierraAPP); // Sintaxis Alterna II
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    //close();
}

void Widget::cerrarApp()
{
    close();
}
