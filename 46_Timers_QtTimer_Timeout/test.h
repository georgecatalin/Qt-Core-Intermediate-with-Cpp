#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>
#include <QTime>
#include <QTimer>

class test : public QObject
{
    Q_OBJECT
public:
    explicit test(QObject *parent = nullptr);

signals:

public slots:
    void timeout();
    void doStuffs();

private:
    QTimer qTimer;
    int number;
};

#endif // TEST_H
