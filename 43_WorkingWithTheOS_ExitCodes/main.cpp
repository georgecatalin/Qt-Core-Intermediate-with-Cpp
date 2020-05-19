#include <QCoreApplication>
#include <QDebug>
#include <QProcess>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QProcess qProcess;

    qInfo()<<"Starting...";
    qProcess.execute("xed",QStringList()<<"www.realitatea.net");
    qInfo()<<"EXIT CODES:\n "
             "Note to self:\n\n "
             "1.0 means it all worked fine.\n "
             "2.Think of the Exit code as the severity of the code.\n "
             "3.0 is the least severe. More than 1 it means something happened and needs to be investigated.\n"
             "\n\n For this process the exist code is="
          <<qProcess.exitCode();

    return a.exec();
}
