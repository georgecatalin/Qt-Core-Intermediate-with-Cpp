#include <QCoreApplication>
#include <QDebug>

QString makeData()
{
    QString data;

    for (int i=0;i<20;i++)
    {
        data.append("Hello, George.\r\n");
    }

    return  data;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString data=makeData();

    QByteArray bytes=data.toLatin1();
    QByteArray encoded=bytes.toHex();
    QByteArray decoded=QByteArray::fromHex(encoded);

    qInfo()<<"Encoded:..."<<encoded;
    qInfo("--------------------------------------");
    qInfo()<<"Decoded:...."<<decoded;

    return a.exec();
}
