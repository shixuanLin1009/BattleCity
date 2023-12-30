#include "Tank.h"
#include "BulletAbility.h"
#include"Obstacle.h"
#include<QList>
Tank::Tank(QGraphicsPixmapItem *parent ,int tankDirection)
    :QGraphicsPixmapItem{parent}
{
    setPixmap(QPixmap(":/img/Player1_Up.png").scaled(40,40));
    setPos(0,0);
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
           return;
        }
    }
}
