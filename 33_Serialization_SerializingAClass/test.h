#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>
#include <QDataStream>
#include <QMap>

class test : public QObject
{
    Q_OBJECT
public:
    explicit test(QObject *parent = nullptr);

    void fill();
    QString getName();
    void setName(QString value);
    QMap<QString,QString> map();

    //serialize the class by overloading the operator so you can save it and read it back QDataStream()
    friend QDataStream&operator <<(QDataStream &stream,const test &t)
    {
        qInfo()<<"Overload <<";
        stream<<t.m_name;
        stream<<t.m_map;

        return stream;
    }

    friend QDataStream&operator >>(QDataStream &stream, test &t)
    {
        qInfo()<<"Overload >>";
        stream>>t.m_name;
        stream>>t.m_map;

        return stream;
    }

signals:

private:
    QString m_name;
    QMap<QString,QString> m_map;

};

#endif // TEST_H
