#ifndef VFFTHREAD_H
#define VFFTHREAD_H

#include <QThread>
#include <QObject>

class VFFThread : public QThread
{
    Q_OBJECT
public:
    VFFThread(int tiempo, QObject *parent = nullptr);
    void setCounter(int);
signals:
    void valueUpdated(int);
protected:
    void run() override;
private:
    int mTiempo;
    int counter;
};

#endif // VFFTHREAD_H
