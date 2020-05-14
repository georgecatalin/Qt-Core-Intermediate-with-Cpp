#include <QCoreApplication>
#include <QDebug>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDir>
#include <QDateTime>

void list(QString path)
{
    qInfo()<<"Listing.... "<<path;

    QDir qDir(path);
    qInfo()<<qDir.absolutePath();

    QFileInfoList dirs=qDir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    QFileInfoList files=qDir.entryInfoList(QDir::Files);

    foreach (QFileInfo fi, dirs)
    {
        qInfo()<<"Directory name..."<<fi.fileName();
    }

    foreach (QFileInfo fi, files)
    {
        qInfo()<<"Filename....";fi.fileName();
        qInfo()<<"Size....."<<fi.size();
        qInfo()<<"Created on...."<<fi.created();
        qInfo()<<"Last modified on..."<<fi.lastModified();
    }

    //make the function to act recursively - enter each directory and get the files from in there

    foreach (QFileInfo fi,dirs)
    {
        list(fi.absolutePath());
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    list(QDir::tempPath());

    return a.exec();
}
