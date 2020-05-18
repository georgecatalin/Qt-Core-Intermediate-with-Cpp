#include <QCoreApplication>
#include <QDebug>
#include <QDataStream>
#include <QFile>
#include <QDir>

/* ***
 * Serialization= writing objects to the disk so to read them later
 * *** */

bool saveFile(QString path)
{
    QFile qFile(path);

    if (qFile.open(QIODevice::WriteOnly)==false)
    {
      return false;
    }

    QDataStream out(&qFile);
    out.setVersion(QDataStream::Qt_5_14);  //set the version of the stream so to be able to easily acknowledge for modifications if Qt details for serialization in future versions change

    QString message="The answer is 42";
    qint64 number=42;

    out<<message;
    out<<number;

    qFile.flush();
    qFile.close();

    return  true;
}

bool readFile(QString path)
{
    QFile qFile(path);

    if (qFile.open(QIODevice::ReadOnly)==false)
    {
        qWarning()<<"Error during the execution of readFile("<<path<<")";
        qWarning()<<qFile.errorString();
        return  false;
    }

    QDataStream in(&qFile);

    if (in.version()!=QDataStream::Qt_5_14)
    {
        qInfo()<<"You are using an older version of the stream. The implementation of the reading QDatastream() class might have changed in your current Qt";
        qFile.close();
        return false;
    }

    QString message;
    qint64 number;

    in>>message;
    in>>number;

    /* *** Note: Mind the order of writing the properties of the objects in the stream. When reading the properties maintain the same order
     * As in the example: firstly read the string, and secondly in order read the number
     * ***/

    qFile.close();

    qInfo()<<"Message is: "<<message;
    qInfo()<<"Number is: "<<number;

    return  true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString file=QDir::currentPath()+QDir::separator()+"test.txt";

    if (saveFile(file))
    {
        qInfo()<<"File saved!!";
    }

    readFile(file);

    return a.exec();
}
