#include "Tank.h"
#include"Obstacle.h"
#include<QList>
Tank::Tank(QGraphicsPixmapItem *parent)
    :QGraphicsPixmapItem{parent}
{
    setPixmap(QPixmap(":/img/Player1_Up.png").scaled(40,40));
    setPos(0,0);
    tankDirection=0;
}

Tank::~Tank(){
    delete this;
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
       if (typeid (*colliding_itmes[i]) == typeid(Tree)){
           setPos(pos);
           return;
       }
       if (typeid (*colliding_itmes[i]) == typeid(Steel)){
           setPos(pos);
           return;
       }
    }
}
