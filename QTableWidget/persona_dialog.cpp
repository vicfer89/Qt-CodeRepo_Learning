#include "persona_dialog.h"
#include "ui_persona_dialog.h"

Persona_Dialog::Persona_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Persona_Dialog)
{
    ui->setupUi(this);
}

Persona_Dialog::~Persona_Dialog()
{
    delete ui;
}

QString Persona_Dialog::nombre() const
{
    return ui->Nombre_line->text();
}

int Persona_Dialog::edad() const
{
    return ui->Edad_spinBox->value();
}

double Persona_Dialog::salario() const
{
    return ui->Salario_doubleSpinBox->value();
}

void Persona_Dialog::on_buttonBox_accepted()
{
    accept();
}

void Persona_Dialog::on_buttonBox_rejected()
{
    reject();
}

void Persona_Dialog::on_buttonBox_helpRequested()
{

}


