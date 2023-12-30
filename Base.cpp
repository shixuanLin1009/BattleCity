#include "Base.h"

Base::Base(QObject *parent,QGraphicsPixmapItem *parent_1)
    :QObject{parent},QGraphicsPixmapItem {parent_1}
{
    setPixmap(QPixmap(":/Obstacles/Base.png").scaled(80,40));
}
