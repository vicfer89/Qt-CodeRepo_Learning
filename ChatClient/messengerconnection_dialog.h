#ifndef MESSENGERCONNECTION_DIALOG_H
#define MESSENGERCONNECTION_DIALOG_H

#include <QDialog>

namespace Ui {
class MessengerConnection_Dialog;
}

class MessengerConnection_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit MessengerConnection_Dialog(QWidget *parent = nullptr);
    ~MessengerConnection_Dialog();

private slots:
    void on_aceptar_pushButton_clicked();

    void on_cancelar_pushButton_clicked();

private:
    Ui::MessengerConnection_Dialog *ui;
};

#endif // MESSENGERCONNECTION_DIALOG_H
