#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "arguments.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(const Arguments &args, QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    Arguments m_args;
};

#endif // WIDGET_H
