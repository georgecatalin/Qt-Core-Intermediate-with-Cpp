#include <QCoreApplication>
#include "watcher.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    watcher w;

    return a.exec();
}
