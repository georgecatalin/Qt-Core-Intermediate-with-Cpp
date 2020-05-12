#include <QCoreApplication>
#include <QDebug>
#include <QSettings>
#include <QStringList>

void saveAge(QSettings* settings,QString group, QString name, int age)
{
    settings->beginGroup(group);
    settings->setValue(name,age);

    settings->endGroup();
}

int readAge(QSettings *settings,QString group, QString name)
{
    settings->beginGroup(group);

    if ((settings->contains(name))==0)
    {
        qWarning()<<"Does not contain"<<name<<" in "<<group;
        settings->endGroup();
        return 0;
    }

    bool ok;
    int value=settings->value(name).toInt(&ok);

    settings->endGroup();

    if (ok==false)
    {
        qWarning()<<"The value can not be converted";
        return 0;
    }

    return  value;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCoreApplication::setOrganizationName("Lacon Electronic");
    QCoreApplication::setOrganizationDomain("lacon.de");
    QCoreApplication::setApplicationName("Learning QSettings");

    QSettings qsettings(QCoreApplication::organizationName(),QCoreApplication::applicationName());

    saveAge(&qsettings,"employee","George",41);
    saveAge(&qsettings,"wines","Merlot Noir",6);
    saveAge(&qsettings,"wines","George",12);

    QStringList people;
    people<<"George"<<"Mara"<<"Zizou";

    foreach (QString person, people)
    {
        saveAge(&qsettings,"test",person, 21);
    }

    qsettings.sync();

    qInfo()<<qsettings.fileName();

    foreach(QString group, qsettings.childGroups())
    {
        qsettings.beginGroup(group);
        qInfo()<<"Group"<<group;
        foreach(QString key, qsettings.childKeys())
        {
            qInfo()<<"Key:.."<<key<<" = "<<qsettings.value(key).toString();
        }
        qsettings.endGroup();
    }

    return a.exec();
}
