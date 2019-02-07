#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushBut_Agregar_released();

private:
    Ui::Widget *ui;

    enum Columnas
    {
        Nombre = 0,
        Edad,
        Salario
    };
};

#endif // WIDGET_H
