#ifndef MAINWINDOW_NOTEPAD_H
#define MAINWINDOW_NOTEPAD_H

#include <QMainWindow>

namespace Ui {
class MainWindow_Notepad;
}

class MainWindow_Notepad : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow_Notepad(QWidget *parent = nullptr);
    ~MainWindow_Notepad();

private slots:
    void on_actionAbrir_triggered();

    void on_actionGuardar_como_triggered();

    void on_actionSalir_triggered();

    void on_actionCopiar_triggered();

    void on_actionCortar_triggered();

    void on_actionPegar_triggered();

    void on_actionAcerca_de_triggered();

    void on_actionFuente_triggered();

    void on_actionTipo_triggered();

    void on_actionColor_triggered();

private:
    Ui::MainWindow_Notepad *ui;
};

#endif // MAINWINDOW_NOTEPAD_H
