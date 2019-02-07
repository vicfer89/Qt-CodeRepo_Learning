#include "explorar_form.h"
#include "ui_explorar_form.h"

Explorar_Form::Explorar_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Explorar_Form)
{
    ui->setupUi(this);
}

Explorar_Form::~Explorar_Form()
{
    delete ui;
}

void Explorar_Form::addFile(const QModelIndex &idx)
{
    ui->explorar_listWidget->addItem(idx.data().toString());
}

void Explorar_Form::on_eliminar_pushButton_released()
{
    delete ui->explorar_listWidget->currentItem();
}


