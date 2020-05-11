#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QtDebug>
#include <QPointer>

class test : public QObject
{
    Q_OBJECT
public:
    explicit test(QObject *parent = nullptr);

    QPointer<QObject> widget; //public data member
    void useWidget();         //public function member

signals:

};

#endif // TEST_H
