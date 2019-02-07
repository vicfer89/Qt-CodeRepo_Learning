#ifndef EXPLORAR_FORM_H
#define EXPLORAR_FORM_H

#include <QWidget>

namespace Ui {
class Explorar_Form;
}

class Explorar_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Explorar_Form(QWidget *parent = nullptr);
    ~Explorar_Form();


    void addFile(const QModelIndex &idx);

private slots:
    void on_eliminar_pushButton_released();

private:
    Ui::Explorar_Form *ui;
};

#endif // EXPLORAR_FORM_H
