#include "widget.h"
#include "ui_widget.h"
#include <QCompleter>
#include <QFileSystemModel>
#include <QFileDialog>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QFileSystemModel *model = new QFileSystemModel(this);;
    model->setRootPath(QDir::rootPath());
    QCompleter *cmpt = new QCompleter(model, this);
    ui->lineEdit->setCompleter(cmpt);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_toolButton_released()
{
    QFile arch;
    QString dir = QFileDialog::getOpenFileName(this, "Abrir");/*QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                                "/home",
                                                                QFileDialog::ShowDirsOnly
                                                                | QFileDialog::DontResolveSymlinks);*/ //Solo carpetas
    ui->lineEdit->setText(dir);

}
