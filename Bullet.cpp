#include "Bullet.h"

Bullet::Bullet(QObject *parent,QGraphicsRectItem *parent_1,int bulletDirection)
    : QObject{parent},QGraphicsRectItem {parent_1}
{
    setRect(0,0,50,50);
    timer = new QTimer();
    connect(timer,&QTimer::timeout,this,&Bullet::shot);
    timer->start(50);
    BulletDirection =bulletDirection;
}

Bullet::~Bullet()
{
    delete timer;
}
void Bullet::shot()
{
    if (BulletDirection == 0){
            moveBy(0,-10);//up
        }
    if (BulletDirection == 1){
            moveBy(10,0);//right
    }
    if (BulletDirection == 2){
            moveBy(0,10);//left
    }
    if (BulletDirection == 3){
            moveBy(-10,0);//down
    }
}

