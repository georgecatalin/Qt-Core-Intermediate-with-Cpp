#include <QCoreApplication>
#include <QDebug>
#include <QDataStream>
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QRandomGenerator>
#include <QIODevice>

bool createFile(QString path)
{
    QFile qFile(path);

    if(qFile.open(QIODevice::WriteOnly)==false)
    {
        qWarning()<<"createFile() error..."<<qFile.errorString();
        return false;
    }

    QDataStream qDatastream(&qFile);
    int max=100;
    QString banner="Random number: ";
    qInfo()<<"Writing "<<banner;

    for (int i=0;i<5;i++)
    {
        qint32 number=QRandomGenerator::global()->bounded(max);
        qInfo()<<"Writing "<<number;
        qDatastream<<number;
    }

    qFile.close();

    return true;
}


void readFile(QString path)
{
    qInfo()<<"Reading file...";
    QFile qFile(path);


    if (qFile.open(QIODevice::ReadOnly)==false)
    {
        qWarning()<<"readFile() error..."<<qFile.errorString();
        return;
    }

    QDataStream qDatastream(&qFile);
    QString banner;
    qDatastream>>banner;
    qInfo()<<"Banner: "<<banner;

    for (int i=0;i<5;i++)
    {
        qint32 num;
        qDatastream>>num;
        qInfo()<<"Random: "<<num;
    }

    qFile.close();
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path=QDir::currentPath()+QDir::separator()+"test";
    qInfo()<<"Path: "<<path;

    if (createFile(path))
    {
        readFile(path);
    }

    return a.exec();
}
