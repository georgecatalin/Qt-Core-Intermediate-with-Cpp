#include <QCoreApplication>
#include "commander.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    commander mycommand;
    mycommand.action(QByteArray("pwd"));
    mycommand.action(QByteArray("ls"));

    return a.exec();
}
