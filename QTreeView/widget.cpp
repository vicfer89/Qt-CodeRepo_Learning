#include "widget.h"
#include "ui_widget.h"
#include <QFileSystemModel>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QFileSystemModel *modelo = new QFileSystemModel(this);
    modelo->setRootPath(QDir::rootPath());
    ui->treeView->setModel(modelo);
}

Widget::~Widget()
{
    delete ui;
}
