#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QRandomGenerator>

QString makeData()
{
    QString data;

    data.append("Unicode test");

    for (int i=0;i<10;i++)
    {
        int number=QRandomGenerator::global()->bounded(1112064);
        data.append(number);
    }
    data.append("\r\n");

    return data;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString data=makeData();
    QString path=QDir::currentPath()+QDir::separator()+"test";

    QFile qFile(path);

    if (qFile.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&qFile);
        stream.setCodec("UTF-8");

        stream<<data;
        stream.flush();

        qFile.close();
    }

    qInfo()<<"Done";
    qInfo()<<"Unicode"<<data;
    qInfo("");
    qInfo()<<"ASCII"<<data.toLatin1();

    return a.exec();
}
