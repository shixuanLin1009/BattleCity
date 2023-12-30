#ifndef BULLETABILITY_H
#define BULLETABILITY_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include<QTimer>
#include<Tank.h>

class BulletAbility:public QGraphicsPixmapItem
{
public:
    BulletAbility(int name, QGraphicsItem *parent = 0);
    void eaten();
};

#endif // BULLETABILITY_H
