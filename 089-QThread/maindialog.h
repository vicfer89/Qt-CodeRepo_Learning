#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>

namespace Ui {
class MainDialog;
}

class ChildDialog;

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainDialog(QWidget *parent = nullptr);
    ~MainDialog();

private:
    Ui::MainDialog *ui;
    ChildDialog *mChildDialog;
};

#endif // MAINDIALOG_H
