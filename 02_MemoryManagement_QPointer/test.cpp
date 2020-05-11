#include "test.h"

test::test(QObject *parent) : QObject(parent)
{

}

void test::useWidget()
{
    /* **** verify if the pointer exists **** */

    if (widget.data()==0)
    {
        qInfo()<<"No pointer exists";
        return;
    }

    qInfo()<<"The pointer is: "<<widget.data();




    /* **** access the pointer **** */
    widget.data()->setObjectName("used Widget");
}
