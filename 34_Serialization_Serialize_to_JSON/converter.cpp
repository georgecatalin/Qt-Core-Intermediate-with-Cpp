#include "converter.h"


converter::converter(QObject *parent) : QObject(parent)
{

}

void converter::writeJson(test *t, QString path)
{
    QVariantMap map;
    QVariantMap items;
    map["name"]=t->getName();

    foreach (QString key, t->map().keys())
    {
        items.insert(key,QVariant(t->map().value(key)));
    }

    map["items"]=QVariant(items);
    QJsonDocument qDocument=QJsonDocument::fromVariant(map);

    QFile qFile(path);
    if(qFile.open(QIODevice::WriteOnly)==false)
    {
        qCritical()<<"Error in writeJson("<<path<<")";
        qCritical()<<qFile.errorString();
        return;
    }

    qFile.write(qDocument.toJson());
    qFile.flush();
    qFile.close();
}

test *converter::readJson(QString path)
{
    QFile qFile(path);
    if(qFile.open(QIODevice::ReadOnly)==false)
    {
        qCritical()<<"Error in readJson("<<path<<")";
        qCritical()<<qFile.errorString();
        return nullptr;
    }

    QByteArray data=qFile.readAll();
    qFile.close();

    QJsonDocument qJsonDocument=QJsonDocument::fromJson(data);
    test *t=new test();

    t->setName(qJsonDocument["name"].toString());
    QVariantMap vmap=qvariant_cast<QVariantMap>(qJsonDocument["items"]);
    QMap<QString,QString> map;

    foreach(QString key,vmap.keys())
    {
        map.insert(key,vmap[key].toString());
    }

    t->setMap(map);

    return  t;
}
