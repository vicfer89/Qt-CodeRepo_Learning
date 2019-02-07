#ifndef PERSONA_H
#define PERSONA_H

#include <QObject>
#include <QDebug>

class Persona : public QObject
{
    Q_OBJECT
public:
    explicit Persona(QObject *parent = nullptr);

    void set_nombre(const QString &nombre);


    void transmite(const QString &palabras);

signals:
    void canal(QString);

public slots:
    void recibe(const QString &palabras);

private:
    QString m_nombre;
};

#endif // PERSONA_H
