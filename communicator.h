#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H
#include <QNetworkAccessManager>

class Communicator : public QObject
{
    Q_OBJECT
public:
    Communicator();
    void sendData();
private:
    QNetworkAccessManager *manager;
public slots:
    void getResponse(QNetworkReply *reply);
};

#endif // COMMUNICATOR_H
