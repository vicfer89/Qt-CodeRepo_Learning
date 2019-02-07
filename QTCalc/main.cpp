#include "widget_qtcalc.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget_QtCalc w;
    w.show();

    return a.exec();
}
