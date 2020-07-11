#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mypushbutton.h"
#include "communicator.h"
#include <QDate>
#include <QTime>
#include <QTimer>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTime);
    ui->setupUi(this);
    updateTime();
    timer->start(1000);
    Communicator *communicator = new Communicator;
    communicator->sendData();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTime()
{
    ui->dateAndTimeLabel->setText("Текущая дата: " + QDate::currentDate().toString(Qt::SystemLocaleLongDate) + "\nТекущее время: " + QTime::currentTime().toString(Qt::SystemLocaleLongDate));
}
