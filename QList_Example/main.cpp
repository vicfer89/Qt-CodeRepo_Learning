#include <QCoreApplication>
#include <QtDebug>
#include <QList>
#include <iostream>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "Inicializando programa:" << std::endl;

    QList<int> L;
    int suma = 0;

    L << 1 << 2 << 3 <<4 << 5 << 6 << 7;
    qDebug() << L;

    QList<int>::Iterator i;
    for(i = L.begin(); i != L.end(); i++)
    {
        suma += *i;
    }
    qDebug() << suma;
    L.removeFirst();
    qDebug() << L;

    suma = 0;
    foreach(int i, L)
    {
        suma += L.value(i);
    }
    qDebug() << suma;

    QString S = "Hola, mi nombre es Victor";
    QStringList Li =S.split(',');
    qDebug() << Li;

    return a.exec();
}
