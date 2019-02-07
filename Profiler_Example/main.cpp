#include <QCoreApplication>
#include <QtDebug>
#include <QTime>
#include <QProcess>
#include <QFile>
#include <QTextStream>

static QFile file;
static QTextStream io;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if(argc == 1)
    {
        qDebug() << QString("Use '%1' programa.exe resultado.txt").arg(argv[0]);
        return 1;
    }

    QTime inicio;
    int dt;
    QProcess proc; // proceso a ejecutar
    QString programa = argv[1];
    QString resultado = argv[2];

    inicio = QTime::currentTime();
    proc.start(programa);
    proc.waitForFinished();
    dt = inicio.msecsTo(QTime::currentTime());

    file.setFileName(resultado);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    io.setDevice(&file);
    io << dt << "ms";

    file.flush();
    file.close();

    qDebug() << dt << "ms";
    qDebug() << "Presione Ctrl+C para terminar";


    return a.exec();
}
