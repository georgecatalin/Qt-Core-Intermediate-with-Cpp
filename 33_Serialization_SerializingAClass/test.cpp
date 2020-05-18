#include "test.h"

test::test(QObject *parent) : QObject(parent)
{

}

void test::fill()
{
    m_name="test object";

    //fill in a map object
    for (int i=0;i<10;i++)
    {
        QString number=QString::number(i);
        QString key="Key: "+number;
        QString value="Value: "+number;

        m_map.insert(key,value);
    }
}

QString test::getName()
{
    return m_name;
}

void test::setName(QString value)
{
    m_name=value;
}

QMap<QString,QString> test::map()
{
    return m_map;
}
