#include <QCoreApplication>
#include <QDebug>
#include "converter.h"
#include "test.h"

void writeJson(QString path)
{
    test t;
    t.fill();
    converter::writeJson(&t,path);
}

void readJson(QString path)
{
    test* t;
    t=converter::readJson(path);

    if (!t)
    {
        qInfo()<<"Object not loaded";
        return;
    }

    qInfo()<<"Name: "<< t->getName();

    foreach (QString key, t->map().keys())
    {
        qInfo()<<key<<" : "<<t->map().value(key);
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

   QString path="test.txt";

   writeJson(path);
   readJson(path);

    return a.exec();
}
