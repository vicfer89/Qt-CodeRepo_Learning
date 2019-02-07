#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("Fusion"); // Para que se quede el estilo fijado
    MainWindow w;
    w.show();

    return a.exec();
}
