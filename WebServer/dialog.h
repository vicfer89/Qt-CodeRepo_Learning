#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class WebServer;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
private slots:
    void mensajeRecibido(const QString &mensaje);

private:
    Ui::Dialog *ui;
    WebServer *mWebServer;
};

#endif // DIALOG_H
