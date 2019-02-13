#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class VFFThread;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_iniciar_PushButton_clicked();

    void on_detener_PushButton_clicked();

    void on_cerrar_PushButton_clicked();

    void on_continuar_PushButton_clicked();

private:
    Ui::Widget *ui;
    VFFThread *mVFFThread1, *mVFFThread2, *mVFFThread3;
};

#endif // WIDGET_H
