#include <QCoreApplication>
#include <QDebug>
#include <QIODevice>
#include <QDir>
#include <QFile>
#include <QString>
#include <QByteArray>
#include <QTextStream>

bool write(QString path,QByteArray data)
{
    QFile qFile(path);

    /* *** verify if for some reason one can not open the file e.g. no rights existing for this *** */
    if (qFile.open(QIODevice::WriteOnly)==false)
    {
        qWarning()<<"Write()...."<<qFile.errorString();
        return false;
    }

    /* *** get the number of bytes write to the file *** */
    qint64 bytes=qFile.write(data);
    qFile.flush();
    qFile.close();

    if (bytes==0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool createFile(QString path)
{
    QByteArray qByteArray;

    for (int i=0;i<5;i++)
    {
        qByteArray.append(QString::number(i));
        qByteArray.append("Hello, World!\r\n");
    }

    return write(path,qByteArray);
}

/* *** read the file all at once, only suitable for small files *** */
void readFile(QString path)
{
    QFile qFile(path);

    /* *** verify if file exists *** */
    if (!qFile.exists())
    {
        qWarning()<<"File does not exist";
        return;
    }

    /* *** verify if file can open *** */
    if (qFile.open(QIODevice::ReadOnly)==false)
    {
        qWarning()<<qFile.errorString();
        return;
    }

    qInfo()<<"****** Reading File";
    qInfo()<<qFile.readAll(); //Best for small files
    qInfo()<<"****** Done";

    qFile.close();
}

/* *** read the file line by line, suitable for text files which can be split into lines *** */
void readLines(QString path)
{
    QFile qFile(path);

    if (qFile.exists()==false)
    {
        qWarning()<<"File does not exist";
        return;
    }

    if (qFile.open(QIODevice::ReadOnly)==false)
    {
        qWarning()<<"Error in Readlines()..."<<qFile.errorString();
        return;
    }

    qInfo()<<".......Reading file!";

    while(!qFile.atEnd())
    {
        QString line(qFile.readLine());
        qInfo()<<"Read by line\n..."<<line.trimmed(); //works best with text files
    }
    qInfo()<<"....Done!";

    qFile.close();
}

void readBytes(QString path)
{
    QFile qFile(path);

    if(!qFile.exists())
    {
        qWarning()<<"File does not exist";
        return;
    }

    if(!qFile.open(QIODevice::ReadOnly))
    {
        qWarning()<<"Error in readBytes()..."<<qFile.errorString();
        return;
    }

    qInfo()<<".....Reading File";

    while(!qFile.atEnd())
    {
        qInfo()<<"Reading by bytes:\n"<<qFile.read(5);
    }

    qInfo()<<"....File read";

    qFile.close();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path=QDir::currentPath()+QDir::separator()+"test";
    qInfo()<<"The path is "<<path;

    if (createFile(path)==true)
    {
        readFile(path);
        readLines(path);
        readBytes(path);
    }



    return a.exec();
}
