#include "agregar_form.h"
#include "ui_agregar_form.h"
#include <QFileSystemModel>

Agregar_Form::Agregar_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Agregar_Form)
{
    ui->setupUi(this);
    mModel = new QFileSystemModel(this);
    mModel -> setRootPath(QDir::homePath());
    ui->Agregar_columnView->setModel(mModel);
}

Agregar_Form::~Agregar_Form()
{
    delete ui;
}

void Agregar_Form::on_Agregar_pushButton_released()
{
    emit selectedFile(ui->Agregar_columnView->currentIndex());
}
