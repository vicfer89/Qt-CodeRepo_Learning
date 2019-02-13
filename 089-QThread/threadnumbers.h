#ifndef THREADNUMBERS_H
#define THREADNUMBERS_H

#include <QThread>

class ThreadNumbers : public QThread
{
    Q_OBJECT
public:
    explicit ThreadNumbers(QObject *parent = nullptr);
    ~ThreadNumbers();

signals:
    void newNumber(int);
protected:
    void run();

public slots:
};

#endif // THREADNUMBERS_H
