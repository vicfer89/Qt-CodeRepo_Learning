#include <QCoreApplication>
#include <QDebug>
#include <QMap>
#include <QFile>
#include <QTextStream>
#include <QTime>

#define TOTAL 10000

static QTextStream io;
static QFile File;
static QMap<int,int> Reg;
static QMap<int, int>::iterator it;
int n = 0;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    File.setFileName("C:/users/VFF/desktop/rand.txt");
    File.open(QIODevice::WriteOnly | QIODevice::Text);
    io.setDevice(&File);

    qsrand(time(NULL)); // generación de numeros aleatorios
    for(int i = 0; i < TOTAL ; ++i)
    {
        io << qrand() % 10 + 1 << ' '; // guardamos como texto en io
    }

    File.flush();
    File.close();

    File.open(QIODevice::ReadOnly | QIODevice::Text);
    while(!File.atEnd())
    {
        io >> n;
        ++Reg[n];
    }
    for(it = Reg.begin() ; it != Reg.end(); ++it)
    {
        qDebug() << it.key() << ":" << it.value();
    }

    return a.exec();
}
