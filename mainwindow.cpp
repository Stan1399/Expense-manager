#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mypushbutton.h"
#include "communicator.h"
#include <QDate>
#include <QTime>
#include <QTimer>
#include <QJsonArray>
#include <QJsonObject>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTime);
    ui->setupUi(this);
    updateTime();
    timer->start(1000);
    setExchangeRates();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTime()
{
    ui->dateAndTimeLabel->setText("Текущая дата: " + QDate::currentDate().toString(Qt::SystemLocaleLongDate) + "\nТекущее время: " + QTime::currentTime().toString(Qt::SystemLocaleLongDate));
}

void MainWindow::setExchangeRates()
{
    Communicator *communicator = new Communicator();
    communicator->sendData();
    QJsonArray jsonArray = communicator->jsonArray;
    foreach (const QJsonValue & value, jsonArray) {
        QJsonObject obj = value.toObject();
        ui->currenciesComboBox->addItem(QString::number(obj["Cur_Scale"].toInt()) + " " + obj["Cur_Name"].toString() + "/" + obj["Cur_Abbreviation"].toString());
        if (obj["Cur_Abbreviation"] == "RUB" || obj["Cur_Abbreviation"] == "EUR" || obj["Cur_Abbreviation"] == "USD")
            ui->exchangeRatesList->addItem(QString::number(obj["Cur_Scale"].toInt()) + " " + obj["Cur_Name"].toString() + "/" + obj["Cur_Abbreviation"].toString() + " " + QString::number(obj["Cur_OfficialRate"].toDouble())/* + " " + QString::number(obj["Cur_ID"].toInt())*/);
    }
//    QGraphicsScene *scene = new QGraphicsScene(0, 0, 300, 300, ui->graphicsView);
//    scene->setBackgroundBrush(Qt::yellow);
//    scene->addRect(QRectF(-10, -10, 20, 20));
//    ui->graphicsView->show();
}

void MainWindow::on_currenciesComboBox_highlighted(int index)
{
    ui->selectedCurrencyRateLabel->setText(QString::number(Communicator::jsonArray[index].toObject()["Cur_OfficialRate"].toDouble()));
}
