#include "widget.h"
#include "ui_widget.h"
#include <QAction>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QAction *agregar, *eliminar;
    agregar = new QAction("Agregar", this); // Acción para menú botón derecho
    eliminar = new QAction("Eliminar", this); // Acción para menú botón derecho
    connect(agregar, SIGNAL(triggered()), this, SLOT(on_pushBut_Agregar_released())); // Conectar acción a SLOT
    connect(eliminar, SIGNAL(triggered()), this, SLOT(on_pushBut_Eliminar_released())); // Conectar acción a SLOT
    ui->listWidget->setContextMenuPolicy(Qt::ActionsContextMenu); // Establecer menú contextual
    ui->listWidget->addAction(agregar); // Agregar acción agregar
    ui->listWidget->addAction(eliminar); // Agregar acción eliminar
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushBut_Agregar_released()
{
    QString nombre = ui->line_Nombre->text();
    if(nombre.isEmpty())
        return;
    ui->listWidget->addItem(nombre);
}

void Widget::on_pushBut_Eliminar_released()
{
    delete ui->listWidget->currentItem();
}
