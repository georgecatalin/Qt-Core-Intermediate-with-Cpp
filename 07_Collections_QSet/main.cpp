#include <QCoreApplication>
#include <QDebug>
#include <QSet>

//QSet is one of Qt's generic classes
//It stores values in an unspecified order and provides very fast lookup of the values, internally

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSet<QString> people;

    people<<"George"<<"Denis"<<"Stefan"<<"Elghin";
    people.insert("Chobbie");

    qInfo()<<people.size();
    qInfo()<<"Is Denis in the list? "<<people.contains("Denis");

    foreach (QString var, people) {
        qInfo()<<var;
    }

    return a.exec();
}
