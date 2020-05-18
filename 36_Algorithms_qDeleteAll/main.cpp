#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include <QtAlgorithms>
#include "test.h"
#include "QString"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<test*> list;

    for(int i=0;i<10;i++)
    {
        test* t=new test();
        t->setObjectName(QString::number(i));
        list.append(t);
    }

    qInfo()<<list.at(0);

    //delete all pointers in memory (ONLY Pointers). It does not delete the objects stored in the list
    qDeleteAll(list);

    //following instruction fetches an error because it gets the first element of the list which is a pointer which does not have content
    //qInfo()<<list.at(0);

    //delete the objects
    list.clear();

    //qInfo()<<list.at(0);

    return a.exec();
}
