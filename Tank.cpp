#include "Tank.h"
#include"Obstacle.h"
#include<QList>
Tank::Tank(QGraphicsPixmapItem *parent)
    :QGraphicsPixmapItem(parent), health(6)
{
    setPixmap(QPixmap(":/img/Player1_Up.png").scaled(40,40));
    setPos(0,0);
    tankDirection=0;
}

void Tank::takeDamage(int damage) {
    health -= damage;
    if (health <= 0) {
        if (scene()) {
            scene()->removeItem(this);
            delete this;
        }
    }
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
    QList <QGraphicsItem*> colliding_items = collidingItems();

    for(int i = 0,n =colliding_items.size();i<n;i++){
       if (typeid (*colliding_items[i]) == typeid(Obstacle)){
           setPos(pos);
           return;
        }
       if (typeid (*colliding_items[i]) == typeid(Steel)){
           setPos(pos);
           return;
       }
       if (typeid (*colliding_items[i]) == typeid(Stone)){
           setPos(pos);
           return;
       }
       if (typeid (*colliding_items[i]) == typeid(Water)){
           setPos(pos);
           return;
       }

    }
}
