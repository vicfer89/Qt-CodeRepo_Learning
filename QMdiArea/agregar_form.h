#ifndef AGREGAR_FORM_H
#define AGREGAR_FORM_H

#include <QWidget>

namespace Ui {
class Agregar_Form;
}

class QFileSystemModel;

class Agregar_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Agregar_Form(QWidget *parent = nullptr);
    ~Agregar_Form();

signals:
    void selectedFile(const QModelIndex &);

private slots:
    void on_Agregar_pushButton_released();

private:
    Ui::Agregar_Form *ui;
    QFileSystemModel *mModel;
};

#endif // AGREGAR_FORM_H
