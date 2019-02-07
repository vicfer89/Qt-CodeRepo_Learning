#include "widget.h"
#include "ui_widget.h"

Widget::Widget(const Arguments &args, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_args = args;

    const int argc = m_args.get_argc();
    char **argv = m_args.get_argv();

    ui->argc_spinBox->setMinimum(0);
    ui->argc_spinBox->setMaximum(INT_MAX);
    ui->argc_spinBox->setValue(argc);

    QStringList myArgs;
    for(int i = 0; i< argc; i++)
    {
        const QString arg = argv[i];
        myArgs << arg;
        ui->argv_textBrowser->append(arg);
    }

}

Widget::~Widget()
{
    delete ui;
}
