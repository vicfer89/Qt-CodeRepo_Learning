#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QProcess>

namespace Ui {
class Widget;
}

class QSystemTrayIcon;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_actionAgregarArgumento_triggered();

    void on_actionEliminarArgumento_triggered();

    void on_ejecutar_pushButton_clicked();

    void on_salir_pushButton_clicked();

    void on_toolButton_clicked();

private:
    void makeConnections();

    Ui::Widget *ui;
    QProcess mProcess;
    QSystemTrayIcon *mTrayIcon;
};

#endif // WIDGET_H
