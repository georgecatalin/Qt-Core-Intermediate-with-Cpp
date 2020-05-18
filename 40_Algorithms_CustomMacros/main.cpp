#include <QCoreApplication>
#include <QDebug>

//Custom macro
#define add(a,b) a+b;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Easy but dangerous
    qInfo()<<add(3,4);

    //Let's break it
    qInfo()<<add("Hello",4);
    qInfo()<<add(true,true);
    qInfo()<<add(true,false);
    qInfo()<<add(false,false);
    qInfo()<<add("Hello",'\n');

    return a.exec();
}
