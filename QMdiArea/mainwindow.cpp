#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "agregar_form.h"
#include "explorar_form.h"
#include <QMdiSubWindow>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->mdiArea);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExplorar_triggered()
{
    mExplorarForm = new Explorar_Form(this);
    loadSubWindow(mExplorarForm);

    if(mAgregarForm)
    {
        connect(mAgregarForm, &Agregar_Form::selectedFile,
                mExplorarForm, &Explorar_Form::addFile);
    }
}

void MainWindow::on_actionAgregar_triggered()
{
    mAgregarForm = new Agregar_Form(this);
    loadSubWindow(mAgregarForm);

    if(mExplorarForm)
    {
        connect(mAgregarForm, &Agregar_Form::selectedFile,
                mExplorarForm, &Explorar_Form::addFile);
    }
}

void MainWindow::on_actionSalir_triggered()
{
    close();
}

void MainWindow::loadSubWindow(QWidget *widget)
{
    auto window = ui->mdiArea->addSubWindow(widget);
    window->setWindowTitle(widget->windowTitle());
    window->setWindowIcon(widget->windowIcon());
    window->show();
}
