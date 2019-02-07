#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class LocalServer;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_iniciar_pushButton_released();

    void on_enviar_pushButton_released();

    void on_salir_pushButton_released();

private:
    Ui::Widget *ui;
    LocalServer *mLocalServer; // Servidor local
};

#endif // WIDGET_H
