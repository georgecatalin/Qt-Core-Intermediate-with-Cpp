#ifndef CONVERTER_H
#define CONVERTER_H

#include <QObject>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QVariant>
#include <QVariantMap>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QMap>
#include "test.h"

class converter : public QObject
{
    Q_OBJECT
public:
    explicit converter(QObject *parent = nullptr);

    static void writeJson(test *t,QString path); //we do these statically so we do not have to create an instance of the class when later using these
    static test* readJson(QString path);

signals:

};

#endif // CONVERTER_H
