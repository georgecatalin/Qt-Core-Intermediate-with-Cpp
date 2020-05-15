#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QLockFile>



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo()<<"Attempting to lock a file....";

    QString path=QDir::currentPath()+QDir::separator()+"test";
    QFile qFile(path);

    QLockFile qLockFile(qFile.fileName()+"l");
    qLockFile.setStaleLockTime(30000); //time is in miliseconds

    if (qLockFile.tryLock())
    {
        qInfo()<<"Putting into file...";
        if (qFile.open(QIODevice::WriteOnly))
        {
            QByteArray qByteArray;
            qFile.write(qByteArray);
            qFile.close();
             qInfo()<<"Finished with the file...";

            qInfo()<<"Unlocking the file....";
            qLockFile.unlock();
        }
    }
    else
    {
        qInfo()<<"Could not unlock file";
        qint64 pid;
        QString hostname;
        QString application;

        if (qLockFile.getLockInfo(&pid,&hostname,&application))
        {
            qInfo()<<"The app is locked by";
            qInfo()<<"Process id: "<<pid;
            qInfo()<<"Host: "<<hostname;
            qInfo()<<"Application: "<<application;
        }
        else
        {
            qInfo()<<"File is locked, but we can not get the info.";
        }
    }



    return a.exec();
}
