#include "mainwindow_notepad.h"
#include "ui_mainwindow_notepad.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include <QFontDialog>
#include <QColorDialog>


MainWindow_Notepad::MainWindow_Notepad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_Notepad)
{
    ui->setupUi(this);
    setCentralWidget(ui->textEdit); // Establece widget central
}

MainWindow_Notepad::~MainWindow_Notepad()
{
    delete ui;
}

void MainWindow_Notepad::on_actionAbrir_triggered()
{
    QFile arch;
    QTextStream io;
    QString filename;
    filename = QFileDialog::getOpenFileName(this, "Abrir");
    if(filename.isEmpty())
        return;
    arch.setFileName(filename);
    arch.open(QIODevice::ReadOnly | QIODevice::Text);
    if(!arch.isOpen())
    {
        QMessageBox::critical(this,"Error", arch.errorString());
        return;
    }
    io.setDevice(&arch);
    ui->textEdit->setText(io.readAll());
    arch.flush();
    arch.close();

}

void MainWindow_Notepad::on_actionGuardar_como_triggered()
{
    QFile arch;
    QTextStream io;
    QString filename;
    filename = QFileDialog::getSaveFileName(this, "Guardar");
    if(filename.isEmpty())
        return;
    arch.setFileName(filename);
    arch.open(QIODevice::WriteOnly | QIODevice::Text);
    if(!arch.isOpen())
    {
        QMessageBox::critical(this,"Error", arch.errorString());
        return;
    }
    io.setDevice(&arch);
    io << ui->textEdit->toPlainText();
    arch.flush();
    arch.close();
}


void MainWindow_Notepad::on_actionSalir_triggered()
{
    close();
}

void MainWindow_Notepad::on_actionCopiar_triggered()
{
    ui->textEdit->copy();
}

void MainWindow_Notepad::on_actionCortar_triggered()
{
    ui->textEdit->cut();
}

void MainWindow_Notepad::on_actionPegar_triggered()
{
    ui->textEdit->paste();
}

void MainWindow_Notepad::on_actionAcerca_de_triggered()
{
    QMessageBox::aboutQt(this,"Qt");
}

void MainWindow_Notepad::on_actionFuente_triggered()
{

}

void MainWindow_Notepad::on_actionTipo_triggered()
{
    bool ok;
    QFont fuente;
    fuente = QFontDialog::getFont(&ok, this);
    if(!ok)
        return;
    ui->textEdit->setFont(fuente);
}

void MainWindow_Notepad::on_actionColor_triggered()
{
    QColor color;
    color = QColorDialog::getColor(Qt::white, this);
    ui->textEdit->setTextColor(color);
}
