#include "test.h"

test::test(QObject *parent) : QObject(parent)
{
    qInfo()<<"Constructed"<<this;
}

test::~test()
{
    qInfo()<<"Deconstructed"<<this;
}
