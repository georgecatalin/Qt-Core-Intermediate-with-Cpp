#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QFileInfo>
#include <QDir>

bool createDirectory(QString path)
{
   QDir qDir(path);

   if (qDir.exists())
   {
       qInfo()<<"Directory already exists!!";
       return true;
   }

   if (qDir.mkpath(path))
   {
       qInfo()<<"Created!!";
       return  true;
   }
   else
   {
       qInfo()<<"Unable to create directory!";
       return false;
   }
}

bool renameFile(QString path,QString name)
{
    QDir qDir(path);

    if (qDir.exists()==false)
    {
        qInfo()<<"The path does not exist.";
        return false;
    }

    //get the position of the last directory separator
    int pos=path.lastIndexOf(QDir::separator());

    //get the string up until the last separator
    QString parent=path.mid(0,pos);

    //set the new path with the new filename
    QString newPath=parent+ QDir::separator() + name;

    qInfo()<<"Absolute: "<<qDir.absolutePath();
    qInfo()<<"Parent: "<<parent;
    qInfo()<<"New Path:"<<newPath;
    qInfo();
    qInfo();

    return  qDir.rename(path,newPath); //the function rename() is attached to the object qDir, and is a member function of QDir Class
}

bool remove(QString path)
{
     qInfo()<<"Removing path:"<<path;

     QDir qDir(path);

     if (qDir.exists()==false)
     {
         qInfo()<<"Path does not exist!";
         return  false;
     }

     qDir.removeRecursively(); //removes anything, despite of it contains or not anything

     return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //get the current path
    QString path=QDir::currentPath();

    //Formulate paths to new files
    QString test=path+QDir::separator()+"test";
    QString temp=path+QDir::separator()+"temp";

    //qInfo()<<path;
    //qInfo()<<test;
    //qInfo()<<temp;

    //Display infos about files in the current working directory
    QDir current(QDir::currentPath());

    if (current.exists())
    {
        foreach (QFileInfo var, current.entryInfoList())
        {
            qInfo()<<var.fileName();
        }
    }

    /* ***
     * Create a directory
     * Rename the directory just created
     * Remove the directory just renamed
     * */

    if (createDirectory(test))
    {
        qInfo()<<"Directory just created!! "<<test;
        if (renameFile(test,"temp"))
        {
            qInfo()<<"I just renamed the file!!"<<temp;
            if (remove(temp))
            {
                qInfo()<<"Success!! Removed the file "<<temp;
            }
            else
            {
                qInfo()<<"Unable to remove the file "<<temp;
            }
        }
    }

    return a.exec();
}
