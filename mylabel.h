#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
private:
    QFont fontForLabel;
public:
    MyLabel(QLabel *parent=nullptr);
    MyLabel(QWidget *parent);

    void resizeEvent(QResizeEvent *);
};

#endif // MYLABEL_H
