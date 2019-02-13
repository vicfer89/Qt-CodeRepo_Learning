#include "childdialog.h"
#include "ui_childdialog.h"
#include "threadnumbers.h"

ChildDialog::ChildDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChildDialog)
{
    ui->setupUi(this);
    mThread =  new ThreadNumbers(this);
    connect(mThread, &ThreadNumbers::newNumber, this, [&](int i){
       ui->listWidget->addItem(QString::number(i));
    });
}

ChildDialog::~ChildDialog()
{
    delete ui;
}

void ChildDialog::on_pushButton_clicked()
{
    close();
}

void ChildDialog::on_pushButton_2_clicked()
{
    mThread->start(QThread::HighestPriority);
}
