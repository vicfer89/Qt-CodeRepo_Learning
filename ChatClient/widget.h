#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>

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
    void on_enviar_pushButton_clicked();

    void on_conectar_pushButton_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket *mSocket;
};

#endif // WIDGET_H
