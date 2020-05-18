#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QDataStream>
#include "test.h"

bool saveFile(test *t, QString path)
{
    QFile qFile(path);
    if (qFile.open(QIODevice::WriteOnly)==false)
    {
        qWarning()<<"Error in saveFile("<<path<<")";
        qWarning()<<qFile.errorString();
        qFile.close();
        return  false;
    }

    QDataStream out(&qFile);
    out.setVersion(QDataStream::Qt_5_14);

    out<<*t;

    qFile.close();
    return true;
}

bool loadFile(QString path)
{
    QFile qFile(path);
    if (qFile.open(QIODevice::ReadOnly)==false)
    {
        qWarning()<<"Error in loadFile("<<path<<")";
        qWarning()<<qFile.errorString();
        qFile.close();
        return false;
    }

    QDataStream in(&qFile);

    test t;
    in>>t;

    qInfo()<<"Name: "<<t.getName();
    foreach (QString key, t.map().keys())
    {
        qInfo()<<key<<" : "<<t.map().value(key);
    }
    qFile.close();
    return  true;

}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path=QDir::currentPath()+QDir::separator()+"test.txt";

    test t;
    t.fill();

    if (saveFile(&t,path))
    {
        loadFile(path);
    }

    return a.exec();
}
