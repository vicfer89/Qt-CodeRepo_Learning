#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class VFFWebServer;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_iniciar_pushButton_clicked();

    void on_salir_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    VFFWebServer *mWebServer;
};

#endif // WIDGET_H
