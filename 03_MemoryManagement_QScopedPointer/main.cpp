#include <QCoreApplication>
#include <QDebug>
#include <QScopedPointer>
#include "test.h"

//The QScopePointer class stores a pointer to a dynamically allocated object and deletes it upon deconstruction.

void usePointer(QObject* obj)
{
    if(obj==0) return;

    qInfo()<<"Using"<<obj;
}

void doStuffs()
{
    //test* obj=new test();
    QScopedPointer<test> myScopedPointer(new test()); //open a QScopedPointer associated with the lifespan of test class, argument is a pointer to a new instance of the class

    usePointer(myScopedPointer.data());

    //scoped pointer is automatically deleted when the function calls off
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    for (int i=0;i<100;i++)
    {
        doStuffs();
    }

    return a.exec();
}
