#include "BulletAbility.h"
#include <QGraphicsScene>
BulletAbility::BulletAbility(int name, QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    if(name == 1){
        setPixmap(QPixmap("").scaled(20,20));
    }
    if(name == 2){
        setPixmap(QPixmap("").scaled(20,20));
    }
    if(name == 3){
        setPixmap(QPixmap("").scaled(20,20));
    }
    if(name == 4){
        setPixmap(QPixmap("").scaled(20,20));
    }
}
void BulletAbility::eaten()
{
QList <QGraphicsItem *>  colliding_items = collidingItems();

for(int i = 0,n =colliding_items.size();i<n;i++){

    if (typeid (*colliding_items[i]) == typeid(Tank)){
        scene()->removeItem(this);
        delete this;
        qDebug() <<"Ability eaten";
        return;
    }
}
}
