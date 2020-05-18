#include <QCoreApplication>
#include <QDebug>
#include <QVector>
#include <QtAlgorithms>



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector<int> list;
    list<<1<<2<<3<<4;

    //the following is deprecated, use the vector
    //qFill(list,0);

    list.fill(0);
    qInfo()<<list;

    return a.exec();
}
