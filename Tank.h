#ifndef TANK_H
#define TANK_H

#include <QObject>
#include <QWidget>
#include<QGraphicsRectItem>

class Tank:public QGraphicsRectItem
{
public:
    Tank(QGraphicsRectItem *parent=nullptr,int tankDirection=0);
    void setDirection(int Direction);
    int getDirection();
private:
    void fire();
    int tankDirection;
};

#endif // TANK_H
