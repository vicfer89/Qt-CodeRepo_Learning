#include "widget.h"
#include "ui_widget.h"
#include "persona_dialog.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(3);
    QStringList Titulos = {"Nombre", "Edad", "Salario"};
    ui->tableWidget->setHorizontalHeaderLabels(Titulos);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushBut_Agregar_released()
{
    Persona_Dialog pd(this); // creamos un dialogo persona al pulsar el botón agregar
    int res = pd.exec(); // ejecutamos el dialogo
    if(res == QDialog::Rejected)
        return;
    else
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem( ui->tableWidget->rowCount() -1,
                                  Widget::Nombre,
                                  new QTableWidgetItem(pd.nombre()) );
        ui->tableWidget->setItem( ui->tableWidget->rowCount() -1,
                                  Widget::Edad,
                                  new QTableWidgetItem(QString::number(pd.edad())) );
        ui->tableWidget->setItem( ui->tableWidget->rowCount() -1,
                                  Widget::Salario,
                                  new QTableWidgetItem(QString::number(pd.salario())) );

    }

}
