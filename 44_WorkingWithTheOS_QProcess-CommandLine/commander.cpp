#include "commander.h"


commander::commander(QObject *parent) : QObject(parent)
{
#ifdef Q_OS_WIN
    //Case of operating system is Windows
    app="cmd";
    endl="\r\n";
#else
    app="bash";
    endl="\n";
#endif

    qProc.setProgram(app);
    qProc.start();

    qProc.setReadChannelMode(QProcess::MergedChannels);

    connect(&qProc,&QProcess::readyRead,this,&commander::readyRead);
    connect(&qProc,&QProcess::readyReadStandardOutput,this,&commander::readyRead);
    connect(&qProc,&QProcess::readyReadStandardError,this,&commander::readyRead);
}

commander::~commander()
{
    if (qProc.isOpen()) qProc.close();
}

void commander::readyRead()
{
    qint64 value=0;
    do
    {
        QByteArray list=qProc.readAll();
        qInfo()<<list.trimmed();

        value=list.length();

    } while (value>0);
}

void commander::action(QByteArray data)
{
    if (!data.endsWith(endl.toLatin1())) data.append(endl);
    qProc.write(data);
    qProc.waitForBytesWritten(1000);
}
