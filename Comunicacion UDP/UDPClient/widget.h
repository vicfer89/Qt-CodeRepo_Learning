#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class QUdpSocket;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_conectar_pushButton_clicked();
    void packet_Received_Signal();

    void on_desconectar_pushButton_clicked();

signals:



private:
    Ui::Widget *ui;
    QUdpSocket *mSocket;
};

#endif // WIDGET_H
