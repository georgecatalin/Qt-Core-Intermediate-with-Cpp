#include "test.h"

test::test(QObject *parent) : QObject(parent)
{
    number=0;
    qTimer.setInterval(1000);

    connect(&qTimer,&QTimer::timeout,this,&test::timeout);
}

void test::timeout()
{
    number++;
    qInfo()<<QTime::currentTime().toString(Qt::DateFormat::SystemLocaleLongDate);

    if (number==5)
    {
        qTimer.stop();
        qInfo()<<"Countdown is complete.";
    }
}

void test::doStuffs()
{
    qTimer.start();
}
