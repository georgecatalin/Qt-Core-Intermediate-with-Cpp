#include <QCoreApplication>
#include <QIODevice>
#include <QBuffer>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QBuffer qBuffer;

    if (qBuffer.open(QIODevice::ReadWrite))
    {
        qInfo()<<"Buffer open ";
        QByteArray qByteArray="Hello, World!";

        for(int i=0;i<5;i++)
        {
            qBuffer.write(qByteArray);
            qBuffer.write("\r\n");
        }

        //for file and device access one needs to flush data on the device
        //qBuffer.flush();

        //move to the 1st position of the buffer
        qBuffer.seek(0);


        //read the entire qByteArray in the memory and display it on the screen with qInfo()
        qInfo()<<qBuffer.readAll();

        qInfo()<<"Closing the qBuffer memory object";

        //ALWAYS close the qBuffer object to avoid deadlocks
        qBuffer.close();
    }
    else
    {
        qInfo()<<"Could not open buffer";
    }



    return a.exec();
}
