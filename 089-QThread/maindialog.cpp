#include "maindialog.h"
#include "ui_maindialog.h"
#include "childdialog.h"

MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);
    mChildDialog = new ChildDialog(this);
    mChildDialog->show();
}

MainDialog::~MainDialog()
{
    delete ui;
}
