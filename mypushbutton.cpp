#include "mypushbutton.h"

MyPushButton::MyPushButton(QPushButton* parent) :
    QPushButton(parent)
{
    fontForButton.setPixelSize(20);
    setFont(fontForButton);
    setText("Hello!");
}
MyPushButton::MyPushButton(QWidget* parent) :
    QPushButton(parent)
{
    fontForButton.setPixelSize(20);
    setFont(fontForButton);
    setText("Hello!");
}

void MyPushButton::resizeEvent(QResizeEvent *event){
    fontForButton.setPixelSize(this->size().height() / 2);
    setFont(fontForButton);
}
