#include <QCoreApplication>
#include <QDebug>
#include <QSettings>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCoreApplication::setOrganizationName("Lacon");
    QCoreApplication::setOrganizationDomain("www.lacon.de");
    QCoreApplication::setApplicationName("Study Qt");

    QSettings qsettings(QCoreApplication::organizationName(), QCoreApplication::applicationName());

    //set the setting
    qsettings.setValue("Laconia",2020);

    //read the setting
    qInfo()<<qsettings.value("Laconia").toString();
    qInfo()<<qsettings.value("Laconia").toInt();

    return a.exec();
}
