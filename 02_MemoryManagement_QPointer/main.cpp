#include <QCoreApplication>
#include <QDebug>
#include <QPointer>
#include "newtest.h"

//QPointer is a template class that provides guarded pointers to QObject

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject* obj=new QObject(nullptr);
    obj->setObjectName("newlyCreatedObject");

    QPointer<QObject> ptr(obj); //wrapped the obj pointer into the smartpointer "ptr"

    newTest nt;
    nt.smartPointer=ptr;
    nt.useSmartPointer();

    delete(obj);
    nt.useSmartPointer();

    return a.exec();
}
