#include <QCoreApplication>
#include <QDebug>
#include <QVector>
#include <QRandomGenerator>

void generateRandom(QVector<int>* list,int maxNoElements)
{
    list->reserve(maxNoElements);

    for (int i=0; i<maxNoElements;i++)
    {
        int value=QRandomGenerator::global()->bounded(1000);
        list->append(value);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector<int> list1;
    generateRandom(&list1,10);

    QVector<int> list2;
    generateRandom(&list2,10);

    qInfo()<<list1;
    qInfo()<<list2;

    //the following is deprecated
    /*
    qInfo()<<"Equal: "<<qEqual(list1.begin(),list1.end(),list2.begin());
    qCopy(list1.begin(),list1.end(),list2.begin());
    qInfo()<<"Equal: "<<qEqual(list1.begin(),list1.end(),list2.begin());
    */

    qInfo()<<"Equal: "<<std::equal(list1.begin(),list1.end(),list2.begin());
    std::copy(list1.begin(),list1.end(),list2.begin());
    qInfo()<<"Equal: "<<std::equal(list1.begin(),list1.end(),list2.begin());

    return a.exec();
}
