#include "mylabel.h"

MyLabel::MyLabel(QLabel* parent) :
    QLabel(parent)
{
    fontForLabel.setPixelSize(20);
    setFont(fontForLabel);
}
MyLabel::MyLabel(QWidget* parent) :
    QLabel(parent)
{
//    fontForLabel.setPixelSize(10);
    fontForLabel.setFamily("Bookman Old Style");
    setFont(fontForLabel);
}

void MyLabel::resizeEvent(QResizeEvent *event){
    if(this->text().contains("\n"))
        fontForLabel.setPixelSize(this->size().height() / 3);
    else
        fontForLabel.setPixelSize(this->size().height() - this->size().height()/5);
    setFont(fontForLabel);
}
