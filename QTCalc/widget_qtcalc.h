#ifndef WIDGET_QTCALC_H
#define WIDGET_QTCALC_H

#include <QWidget>

namespace Ui {
class Widget_QtCalc;
}

class Widget_QtCalc : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_QtCalc(QWidget *parent = nullptr);
    ~Widget_QtCalc();

private slots:
    void on_pBut_Suma_released();

    void on_pBut_Resta_released();

    void on_pBut_Multiplica_released();

    void on_pBut_Divide_released();

    void on_pushButton_released();

private:
    Ui::Widget_QtCalc *ui;
};

#endif // WIDGET_QTCALC_H
