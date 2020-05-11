#include "consumer.h"

consumer::consumer(QObject *parent) : QObject(parent)
{
    qInfo()<<"Constructed  "<<this;
}

consumer::~consumer()
{
    qInfo()<<"Deconstructed  "<<this;
}
