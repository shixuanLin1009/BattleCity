#include "Bullet.h"

Bullet::Bullet(QObject *parent,QGraphicsRectItem *parent_1)
    : QObject{parent},QGraphicsRectItem {parent_1}
{
    setRect(0,0,50,50);
    timer = new QTimer();
    connect(timer,&QTimer::timeout,this,&Bullet::shot);
    timer->start(50);
}

Bullet::~Bullet()
{
    delete timer;
}
void Bullet::shot()
{
    setPos(x(),y()-10);
}
