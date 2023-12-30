#ifndef TANK_H
#define TANK_H

#include <QObject>
#include <QWidget>
#include<QGraphicsPixmapItem>


class Tank:public QGraphicsPixmapItem
{
public:
    Tank(QGraphicsPixmapItem *parent=nullptr);
    void setDirection(int Direction);
    int getDirection();
    void checkColliging(QPointF pos);
signals:
    void tankHitsObstacle();
    void destroyed();
private:
    void fire();
    int tankDirection;
};

#endif // TANK_H
