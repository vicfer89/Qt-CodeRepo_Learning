#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPointer>

namespace Ui {
class MainWindow;
}

class Agregar_Form;
class Explorar_Form;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionExplorar_triggered();

    void on_actionAgregar_triggered();

    void on_actionSalir_triggered();

private:
    Ui::MainWindow *ui;
    QPointer<Agregar_Form> mAgregarForm;
    QPointer<Explorar_Form> mExplorarForm;

    void loadSubWindow(QWidget *widget);
};

#endif // MAINWINDOW_H
