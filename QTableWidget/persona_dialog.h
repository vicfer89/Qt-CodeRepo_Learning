#ifndef PERSONA_DIALOG_H
#define PERSONA_DIALOG_H

#include <QDialog>

namespace Ui {
class Persona_Dialog;
}

class Persona_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Persona_Dialog(QWidget *parent = nullptr);
    ~Persona_Dialog();

    QString nombre() const;
    int edad() const;
    double salario() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_helpRequested();

    void on_buttonBox_rejected();

private:
    Ui::Persona_Dialog *ui;
};

#endif // PERSONA_DIALOG_H
