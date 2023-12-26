#include "BulletAbility.h"

BulletAbility::BulletAbility(QGraphicsItem *parent,QString name):QGraphicsPixmapItem(parent)
{
    if(name == "1"){
        setPixmap(QPixmap("").scaled(20,20));
    }
    if(name == "2"){
        setPixmap(QPixmap("").scaled(20,20));
    }
    if(name == "3"){
        setPixmap(QPixmap("").scaled(20,20));
    }
    if(name == "4"){
        setPixmap(QPixmap("").scaled(20,20));
    }
}
