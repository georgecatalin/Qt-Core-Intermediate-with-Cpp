#include <QCoreApplication>
#include <QIODevice>
#include <QDir>
#include <QFile>
#include <QString>
#include <QByteArray>
#include <QDebug>


bool put(QString path,QByteArray data,QIODevice::OpenMode mode)
{
    QFile qFile(path);

    if (qFile.open(mode)==false)
    {
        qInfo()<<qFile.errorString();
        return false;
    }

    //obtain the bytes to write with data
    qint64 bytes=qFile.write(data);

    if (bytes==0)
    {
        qWarning()<<"Problem..."<<qFile.errorString();
    }
    else
    {
        qInfo()<<"Success!!...I wrote "<<bytes<<" to the file"<<qFile.fileName();
    }

    qFile.flush(); //this is a binary operation and returns true if successful
    qFile.close();

    return true;
}

void write(QString path,QByteArray data)
{
    qInfo()<<"Writing to file...";
    if (put(path,data,QIODevice::WriteOnly)==true) //WriteOnly deletes everything before adding the data in the file
    {
        qInfo()<<"Data written to file";
    }
    else
    {
        qWarning()<<"Failed to write to file";
    }
}

void append(QString path,QByteArray data)
{
    qInfo()<<"Appending to file...";

    if (put(path,data,QIODevice::Append)==true) //Append adds the data to the end of the file
    {
        qInfo()<<"Data appended to file";
    }
    else
    {
        qWarning()<<"Failed to append to file";
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path=QDir::currentPath()+QDir::separator()+"test";
    qInfo()<<"The new path is: "<<path;

    //set a QByteArray object
    QByteArray qByteArray("Hello, World!\r\n");

    for(int i=0;i<5;i++)
    {
        QString num=QString::number(i);
        num.append(" ");

        //set a QByteArray object
        QByteArray line(num.toLatin1()+qByteArray);

        //write(path,line); //deletes the file and recreates it everytime it is adding data to the file
        append(path,line); //each time it appends data at the end of the file
    }

    return a.exec();
}
