#include "newtest.h"

newTest::newTest(QObject *parent) : QObject(parent)
{

}

void newTest::useSmartPointer()
{
    /* *** step 1: verify if smart pointer exists *** */

    if (smartPointer.data()==0)
    {
        qInfo()<<"No smart pointer exists in the stack";
        return;
    }

    qInfo()<<"The smart pointer is:"<<smartPointer.data();

    /* *** step 2:  access the smart pointer *** */
    smartPointer.data()->setObjectName("newObjectName");
}
