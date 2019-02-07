#include <QCoreApplication>
#include <QDebug>
#include <QDateTime>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDate Date(2019, 01, 15);
    QTime Time(15,31,00);
    QDateTime fh(Date,Time);

    qDebug() << QDateTime::currentDateTimeUtc();

    return a.exec();
}
