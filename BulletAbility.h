#ifndef BULLETABILITY_H
#define BULLETABILITY_H
#include <QGraphicsPixmapItem>

class BulletAbility:public QGraphicsPixmapItem
{
public:
    BulletAbility(QGraphicsItem *parent = 0,QString name = "");
};

#endif // BULLETABILITY_H
