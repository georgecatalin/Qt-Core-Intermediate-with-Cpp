#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QProcess>

bool test()
{
    QProcess qProcess;

    qProcess.start("gzip",QStringList()<<"-c");

    if (qProcess.waitForStarted()==false) return  false;

    qProcess.write("This text will be compressed with GZip.");
    qProcess.closeWriteChannel();

    if (qProcess.waitForFinished()==false) return false;
    QByteArray result=qProcess.readAll();

    qInfo()<<"The result of the process is "<<result;

    return  true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if(test())
    {
        qInfo()<<"Text archived correctly with gzip.";
    }
    else
    {
        qInfo()<<"Failed to archive with gzip.";
    }

    return a.exec();
}
