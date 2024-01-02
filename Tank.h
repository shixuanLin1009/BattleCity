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
    void takeDamage(int damage); // 處理所受傷害
protected:
    int health; // 生命值
signals:
    void tankHitsObstacle();
    void destroyed();
private:
    void fire();
    int tankDirection;
};

#endif // TANK_H
