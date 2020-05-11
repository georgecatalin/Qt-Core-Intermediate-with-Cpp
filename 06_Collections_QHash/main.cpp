#include <QCoreApplication>
#include <QDebug>
#include <QHash>

//QHash works well with static info that does not change too much
//QHash<Key,T> is one of Qt's container generic classes
//It stores key,value pairs and provides fast lookup of the values

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QHash<QString,int> ages;

    ages.insert("George",41);
    ages.insert("Cornel",46);
    ages.insert("Sandu",66);
    ages.insert("Sorina",42);
    ages.insert("Mara",8);

    qInfo()<<"The age of George is "<<ages["George"]<<" years";
    qInfo()<<"Keys: "<<ages.keys();
    qInfo()<<"Size is"<<ages.size();

    foreach (QString key, ages.keys()) {
        qInfo()<<key<<" = "<<ages[key];
    }

    return a.exec();
}
