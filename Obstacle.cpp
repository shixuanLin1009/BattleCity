#include "Obstacle.h"

Obstacle::Obstacle(QGraphicsPixmapItem *parent)
    :QGraphicsPixmapItem{parent}
{
    setPixmap(QPixmap(":/img/Stone.png").scaled(40,40));

}


