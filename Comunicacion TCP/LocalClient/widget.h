#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class QTcpSocket;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_conectar_pushButton_clicked();

    void on_salir_pushButton_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket *mSocket;
};

#endif // WIDGET_H
