#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDir>

QByteArray makeData()
{
    QByteArray data;

    for (int i=0;i<10;i++)
    {
        data.append(72);
        data.append(101);
        data.append(108);
        data.append(111);
        data.append(38);
        data.append(111);
        data.append(13); // \r
        data.append(10); // \n
    }

    return  data;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QByteArray data=makeData();

    QString path=QDir::currentPath()+QDir::separator()+"test";
    QFile qFile(path);

    if(qFile.open(QIODevice::WriteOnly))
    {
        qFile.write(data);
        qFile.close();
    }


    qInfo()<<"Done";
    return a.exec();
}
