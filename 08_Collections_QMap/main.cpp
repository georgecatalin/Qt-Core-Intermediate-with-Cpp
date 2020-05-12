#include <QCoreApplication>
#include <QDebug>
#include <QMap>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap<QString,int> qMap;

    qMap.insert("George",41);
    qMap.insert("Burssen",42);
    qMap.insert("Bibestoss",8);
    qMap.insert("Zizou",1);

    qInfo()<<"George has "<<qMap["George"];
    qInfo()<<"Keys:"<<qMap.keys();

    foreach (QString key, qMap.keys())
    {
        qInfo()<<key<<" = "<<qMap[key];
    }

    return a.exec();
}
