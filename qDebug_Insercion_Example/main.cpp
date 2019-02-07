#include <QCoreApplication>
#include <QDebug>

class persona
{
public:
    persona(const QString &nombre)
    {
        m_nombre = nombre;
    }
    persona();
    persona(QString &nombre, int edad) : m_nombre(nombre), m_edad(edad) {}

    friend inline QDebug operator<<(QDebug qd, const persona &p); // sobrecarga para operador QDebug

private:
    QString m_nombre;
    int m_edad = 0;
};

inline QDebug operator<<(QDebug qd, const persona &p) // Funcion de sobrecarga de operador
{
    return qd << p.m_nombre << " " << p.m_edad;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    persona juan = static_cast<QString> ("Juan");
    qDebug() << juan;

    return a.exec();
}
