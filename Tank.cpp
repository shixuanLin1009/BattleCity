#include "Tank.h"
#include"Obstacle.h"
#include<QList>

Tank::Tank(QGraphicsPixmapItem *parent)
    :QGraphicsPixmapItem{parent}
{
    setPixmap(QPixmap(":/img/Player1_Up.png").scaled(40,40));
    setZValue(1);
    setPos(0,0);
    tankDirection=0;
    m_Speed=20;
}

void Tank::setDirection(int Direction)
{
    tankDirection = Direction;
}

int Tank::getDirection()
{
    return tankDirection;
}

void Tank::checkColliging(QPointF pos)
{
    QList <QGraphicsItem*> colliding_itmes = collidingItems();

    for(int i = 0,n =colliding_itmes.size();i<n;i++){
       if (typeid (*colliding_itmes[i]) == typeid(Obstacle)){
           setPos(pos);
           setSpeed(20);
           return;
        }
       if (typeid (*colliding_itmes[i]) == typeid(Steel)){
           setPos(pos);
           return;
       }
       if (typeid (*colliding_itmes[i]) == typeid(Ice)){
           setSpeed(40);
           return;
       }
       if (typeid (*colliding_itmes[i]) == typeid(Water)){
           setSpeed(10);
           return;
       }
    }
}

int Tank::Speed() const
{
    return m_Speed;
}

void Tank::setSpeed(int newSpeed)
{
    m_Speed = newSpeed;
}

void Tank::normal()
{
    setSpeed(20);
}
