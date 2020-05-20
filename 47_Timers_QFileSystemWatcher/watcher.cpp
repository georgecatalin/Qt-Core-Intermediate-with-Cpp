#include "watcher.h"


watcher::watcher(QObject *parent) : QObject(parent)
{
    //Set the files and directories to watch
    qFileSystemWatcher.addPath(QDir::currentPath());
    qFileSystemWatcher.addPath(QDir::currentPath()+QDir::separator()+"test.txt");

    connect(&qFileSystemWatcher,&QFileSystemWatcher::fileChanged,this,&watcher::fileChanged);
    connect(&qFileSystemWatcher,&QFileSystemWatcher::directoryChanged,this,&watcher::directoryChanged);
}

void watcher::directoryChanged(const QString &path)
{
    qInfo()<<"Directory changed in "<<path;

    if (qFileSystemWatcher.directories().length()!=0)
    {
        qInfo()<<"The following directories have changed: ";
        foreach(QString directory,qFileSystemWatcher.directories())
        {
            qInfo()<<directory;
        }
    }
}

void watcher::fileChanged(const QString &path)
{
    qInfo()<<"Files changed in "<<path;

    if (qFileSystemWatcher.files().length()!=0)
    {
        qInfo()<<"These files have changed:";
        foreach (QString pathFile, qFileSystemWatcher.files())
        {
            qInfo()<<pathFile;
        }
    }
}
