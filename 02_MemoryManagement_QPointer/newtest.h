#ifndef NEWTEST_H
#define NEWTEST_H

#include <QObject>
#include <QDebug>
#include <QPointer>

class newTest : public QObject
{
    Q_OBJECT
public:
    explicit newTest(QObject *parent = nullptr);

    QPointer<QObject> smartPointer; //datamember of the class
    void useSmartPointer(); //function member of the class

signals:

};

#endif // NEWTEST_H
