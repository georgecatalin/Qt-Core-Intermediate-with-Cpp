#ifndef CONSUMER_H
#define CONSUMER_H

#include <QObject>
#include <QDebug>
#include <QSharedPointer>
#include "test.h"

class consumer : public QObject
{
    Q_OBJECT
public:
    explicit consumer(QObject *parent = nullptr);
    ~consumer();

    QSharedPointer<test> mySharedPointer;

signals:

};

#endif // CONSUMER_H
