#include <QCoreApplication>
#include <QDebug>
#include <QIODevice>
#include <QDir>
#include <QFile>
#include <QRandomGenerator>
#include <QTextStream>

bool createFile(QString path)
{
    qInfo()<<"...create file...";

    QFile qFile(path);
    if (qFile.open(QIODevice::WriteOnly)==false)
    {
        qWarning()<<"error in createFile()..."<<qFile.errorString();
        return false;
    }

    QTextStream qTextStream(&qFile);

    QString header="Hello\r\n";

    qInfo()<<"Writing from stream to file..."<<header;
    qTextStream<<header;

    for (int i=0;i<10;i++)
    {
        qint16 number=QRandomGenerator::global()->bounded(100);
        qInfo()<<"Writing "<<number<<" to stream";
        qTextStream<<number<<"\r\n";
    }


    qFile.close();
    return true;
}

void readFile(QString path)
{
    qInfo()<<"..read file...";

    QFile qFile(path);

    if (qFile.open(QIODevice::ReadOnly)==false)
    {
        qWarning()<<"error in readFile()"<<qFile.errorString();
        return;
    }

    QTextStream qTextStream(&qFile);

    QString header;
    qTextStream>>header;

    qInfo()<<"Reading header.."<<header;

    for (int i=0;i<5;i++)
    {
        QString number; //this time not a qint32 because we are not reading a number anymore, but a string
        qTextStream>>number;

        qInfo()<<"Random"<<number;
    }


}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path=QDir::currentPath()+QDir::separator()+"test";
    qInfo()<<"The path is: "<<path;

    if (createFile(path))
    {
        readFile(path);
    }

    return a.exec();
}
