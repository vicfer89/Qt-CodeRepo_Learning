#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include <QVariant>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<int> v {1, 2, 3 ,4 ,5 , 6, 7, 8, 9, 10};
    qDebug() << v;
    foreach(int i , v)
    {
        qDebug() << i;
    }

    QVariant variant;

    return a.exec();
}
