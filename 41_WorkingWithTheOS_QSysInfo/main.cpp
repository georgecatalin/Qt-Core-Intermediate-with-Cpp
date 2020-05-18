#include <QCoreApplication>
#include <QDebug>
#include <QSysInfo>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSysInfo qSysInfo;

    qInfo()<<"System info";
    qInfo()<<"Boot id: "<<qSysInfo.bootUniqueId();
    qInfo()<<"Build: "<<qSysInfo.buildAbi();
    qInfo()<<"CPU Architecture: "<<qSysInfo.buildCpuArchitecture();
    qInfo()<<"Kernel:  "<<qSysInfo.kernelType();
    qInfo()<<"Version: "<<qSysInfo.kernelVersion();
    qInfo()<<"Mac: "<<qSysInfo.macVersion();
    qInfo()<<"Windows: "<<qSysInfo.windowsVersion();
    qInfo()<<"Host: "<<qSysInfo.machineHostName();
    qInfo()<<"Product: "<<qSysInfo.prettyProductName();
    qInfo()<<"Type: "<<qSysInfo.productType();
    qInfo()<<"Version: "<<qSysInfo.productVersion();

#ifdef Q_OS_LINUX
    qInfo()<<"Linux code here...";
#elif defined(W_OS_WIN32)
    qInfo()<<"Windows code here..."
         #elif defined(W_OS_MACX)
    qInfo()<<"Mac code here...";
#else
    qInfo()<<"Unknown code here..."
#endif

    return a.exec();
}
