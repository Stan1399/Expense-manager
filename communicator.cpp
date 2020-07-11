#include "communicator.h"
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <vector>

Communicator::Communicator()
{
    manager = new QNetworkAccessManager;
}

void Communicator::sendData() {
    QNetworkRequest request(QUrl("https://www.nbrb.by/api/exrates/rates?periodicity=0"));
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getResponse(QNetworkReply*)));
    manager->get(request);
}

void Communicator::getResponse(QNetworkReply *reply)
{
    QString str = reply->readAll();
    qDebug() << str;
    reply->deleteLater();
    QStringList Cur_Abbreviation;
    std::vector<int> Cur_ID;
    QJsonDocument jsonResponse = QJsonDocument::fromJson(str.toUtf8());
    qDebug() << jsonResponse.isArray();
    QJsonArray jsonArray = jsonResponse.array();
    foreach (const QJsonValue & value, jsonArray) {
        QJsonObject obj = value.toObject();
        Cur_Abbreviation.append(obj["Cur_Abbreviation"].toString());
        Cur_ID.push_back(obj["Cur_ID"].toInt());
        qDebug() << Cur_Abbreviation[Cur_Abbreviation.length()-1] << ' ' << Cur_ID[Cur_ID.size()-1];
    }

//    foreach (const QString & key, keys) {
//        QJsonValue value = rootObject.value(key);
//        if (value.isDouble())
//        {
//            qDebug() << key << ' ' << value.toDouble();
//        }
//        else
//        {
//            qDebug() << key << ' ' << value.toString();
//        }

//        propertyNames.append(rootObject.value(key).toString());
//        propertyKeys.append(key);/*
//        qDebug() << propertyKeys[propertyKeys.length()-1] << ' ' << propertyNames[propertyNames.length()-1];*/

//    }

}
