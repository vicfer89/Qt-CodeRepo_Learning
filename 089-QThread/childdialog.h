#ifndef CHILDDIALOG_H
#define CHILDDIALOG_H

#include <QDialog>

namespace Ui {
class ChildDialog;
}

class ThreadNumbers;

class ChildDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChildDialog(QWidget *parent = nullptr);
    ~ChildDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ChildDialog *ui;
    ThreadNumbers *mThread;
};

#endif // CHILDDIALOG_H
