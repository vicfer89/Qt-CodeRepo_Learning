#include "messengerconnection_dialog.h"
#include "ui_messengerconnection_dialog.h"

MessengerConnection_Dialog::MessengerConnection_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MessengerConnection_Dialog)
{
    ui->setupUi(this);
}

MessengerConnection_Dialog::~MessengerConnection_Dialog()
{
    delete ui;
}

void MessengerConnection_Dialog::on_aceptar_pushButton_clicked()
{

}

void MessengerConnection_Dialog::on_cancelar_pushButton_clicked()
{

}
