#include <QCoreApplication>
#include <QtDebug>
#include <QDataStream>
#include <QFile>
#include <QString>

class Persona
{

public:
        Persona(void)
        {

        }

        Persona(const QString &nombre, int edad, double salario)
            : m_nombre(nombre), m_edad(edad), m_salario(salario)
        {

        }

        friend inline QDataStream &operator<<(QDataStream &ds, const Persona &p);
        friend inline QDataStream &operator>>(QDataStream &ds, Persona &p);
        friend inline QDebug &operator<<(QDebug qd, const Persona &p);

private:
        QString m_nombre;
        int m_edad;
        double m_salario;
};

inline QDataStream &operator<<(QDataStream &ds, const Persona &p)
{
    return ds << p.m_nombre << p.m_edad << p.m_salario;
}

inline QDataStream &operator>>(QDataStream &ds, Persona &p)
{
    return ds >> p.m_nombre >> p.m_edad >> p.m_salario;
}

inline QDebug &operator<<(QDebug qd, const Persona &p)
{
    return qd << p.m_nombre << p.m_edad << p.m_salario;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDataStream IOData;
    QFile File;
    Persona persona; /*persona("Victor", 29, 1500.0)*/;

    File.setFileName("C:/users/VFF/Desktop/FicheroDatos.txt");
    File.open(QIODevice::ReadOnly);

    IOData.setDevice(&File);
    IOData.setVersion(QDataStream::Qt_5_12);

    //IOData << persona;
    IOData >> persona;

    File.flush();
    File.close();

    qDebug() << persona;

    return a.exec();
}
