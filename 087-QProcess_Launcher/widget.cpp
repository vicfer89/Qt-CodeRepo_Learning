#include "widget.h"
#include "ui_widget.h"
#include <QSystemTrayIcon>
#include <QInputDialog>
#include <QFileDialog>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
   // mTrayIcon->setVisible(true);
    //mTrayIcon->setIcon(QIcon);
    //mTrayIcon->show();
    makeConnections();

    ui->argumentos_listWidget->addActions({ui->actionAgregarArgumento,
                                           ui->actionEliminarArgumento });

}

Widget::~Widget()
{
    delete ui;
}

void Widget::makeConnections()
{
    auto finishedSignal =  static_cast<void (QProcess::*)(int)>(&QProcess::finished);
    connect(&mProcess, finishedSignal, [&](int exitCode){
        mTrayIcon->showMessage(tr("Mensaje"), tr("Proceso terminado...: %1").arg(exitCode));
    });

    connect(&mProcess, &QProcess::started, [&](){
        mTrayIcon->showMessage(tr("Mensaje"), tr("Proceso iniciado..."));
    });
}

void Widget::on_actionAgregarArgumento_triggered()
{
    bool ok;
    auto args = QInputDialog::getMultiLineText(this, tr("Argumento"), tr("Argumento"),"",&ok);
    if(!ok || args.isEmpty()) {
       return;
    }
    else {
        ui->argumentos_listWidget->addItem(new QListWidgetItem(args));
    }
}

void Widget::on_actionEliminarArgumento_triggered()
{
    delete ui->argumentos_listWidget->currentItem();
}

void Widget::on_ejecutar_pushButton_clicked()
{
    auto program = ui->program_lineEdit->text();
    const int argc = ui->argumentos_listWidget->count();
    QStringList args;
    for(int i = 0; i < argc; ++i)
    {
        args << ui->argumentos_listWidget->item(i)->text();
    }
    mProcess.setProgram(program);
    mProcess.setArguments(args);
    mProcess.start();
}

void Widget::on_salir_pushButton_clicked()
{
    close();
}

void Widget::on_toolButton_clicked()
{
    auto filename = QFileDialog::getOpenFileName(this, tr("Abrir"),"/", "EXE files (*.exe)");
    if(filename.isEmpty()){
        return;
    }
    else {
        ui->program_lineEdit->setText(filename);
    }
}
