#include <QCoreApplication>
#include <QDebug>
#include <QRandomGenerator>
#include <QVector>

void generateRandom(QVector<int> *list,int max)
{
    list->reserve(max);
    for(int i=0;i<max;i++)
    {
        int value=QRandomGenerator::global()->bounded(1000);
        list->append(value);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector<int> list;
    generateRandom(&list,10);

    qInfo()<<"Unsorted.."<<list;

    //the following is deprecated, use std::sort instead
    //qSort(list);

    std::sort(list.begin(),list.end());

    qInfo()<<"Sorted..."<<list;

    return a.exec();
}
