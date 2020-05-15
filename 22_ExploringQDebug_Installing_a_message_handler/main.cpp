#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDateTime>

const QtMessageHandler QT_DEFAULT_MESSAGE_HANDLER=qInstallMessageHandler(nullptr); //add a default message handler




int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo()<<"This is a info message.";
    qDebug()<<"This is a debug message.";
    qWarning()<<"This is a warning message.";
    qCritical()<<"This is a critical message.";
    qFatal("This a fatal message and it kills the program!!");

    return a.exec();
}
