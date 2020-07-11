#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
private:
    QFont fontForButton;
public:
    MyPushButton(QPushButton *parent=nullptr);
    MyPushButton(QWidget *parent);

    void resizeEvent(QResizeEvent *);
};

#endif // MYPUSHBUTTON_H
