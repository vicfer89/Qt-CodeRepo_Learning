#include "widget.h"
#include "ui_widget.h"
#include <QRegExpValidator>

#define EMAIL_RX_VAL "^[0-9a-zA-Z]+([0-9a-zA-Z][-._+])[0-9a-zA-Z]+@[0-9a-zA-Z]+([-.][0-9a-zA-Z]+)([0-9a-zA-Z][.])[a-zA-Z]{2,6}$"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QRegExp email_rx(EMAIL_RX_VAL);
    QRegExpValidator *valid_email = new QRegExpValidator(email_rx, this);
    ui->email_lineEdit->setValidator(valid_email);

}

Widget::~Widget()
{
    delete ui;
}
