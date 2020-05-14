#include <QCoreApplication>
#include <QDebug>
#include <QFileInfo>
#include <QDir>
#include <QStorageInfo>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    foreach (QStorageInfo qStorageInfo, QStorageInfo::mountedVolumes())
    {
        qInfo()<<"Display name..."<<qStorageInfo.displayName();
        qInfo()<<"Type...."<<qStorageInfo.fileSystemType();
        qInfo()<<"Total Size..."<<qStorageInfo.bytesTotal()/1000000<< " MB";
        qInfo()<<"Available size"<<qStorageInfo.bytesAvailable()/1000000<<" MB";
        qInfo()<<"Is mounted on root?...."<<qStorageInfo.isRoot();
        qInfo()<<"Device name..."<<qStorageInfo.device();
        qInfo("");
    }

    //get the infos about the root
    QStorageInfo root=QStorageInfo::root();
    QDir qDir(root.rootPath());

    foreach (QFileInfo fi, qDir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot))
    {
        qInfo()<<fi.filePath();
    }

    return a.exec();
}
