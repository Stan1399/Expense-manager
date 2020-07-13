#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H
#include <QNetworkAccessManager>
#include <QJsonArray>
#include <QListWidget>
#include "mainwindow.h"

class Communicator : public QObject
{
    Q_OBJECT
public:
    static QJsonArray jsonArray;
    Communicator();
    void sendData();
private:
    QNetworkAccessManager *manager;
public slots:
    void getResponse(QNetworkReply *reply);
};

#endif // COMMUNICATOR_H
