#include <QCoreApplication>
#include <QDebug>
#include <QSharedPointer>
#include "consumer.h"
#include "test.h"

/* *** QSharedPointer will delete the pointer it is holding when it goes out of scope ,provided no other QSharedPointers are accessing it *** */

void deletePointer(test* obj)
{
    qInfo()<<"Deleting..."<<obj;
    obj->deleteLater();
}

QSharedPointer<test> createSharedPointer()
{
    test* t=new test();
    t->setObjectName("Test Object");

    QSharedPointer<test> ptr(t,deletePointer);
    return ptr;
}

void doStuff(QSharedPointer<consumer> ptr )
{
    qInfo()<<"In function: "<<ptr.data()->mySharedPointer;
    ptr.clear(); //does not delete the pointer, just removes the references
}

QSharedPointer<consumer> makeConsumer()
{
    QSharedPointer<consumer> c(new consumer, &QObject::deleteLater);
        QSharedPointer<test> t = createSharedPointer();

        c.data()->mySharedPointer.swap(t);
        doStuff(c);

        return c;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QSharedPointer<consumer> consume = makeConsumer();
    qInfo() << "In main: " << consume.data()->mySharedPointer;

    consume.clear(); //Does not actually delete!, just removes the reference

    return a.exec();
}
