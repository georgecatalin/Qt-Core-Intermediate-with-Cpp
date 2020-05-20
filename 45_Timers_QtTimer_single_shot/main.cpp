#include <QCoreApplication>
#include <QTimer>
#include <QDebug>

void test()
{
    qInfo()<<"Thank you for waiting...";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo()<<"Please wait...";

    QTimer::singleShot(5000,&test);

    return a.exec();
}
