#include "Tank.h"

Tank::Tank(QGraphicsPixmapItem *parent ,int tankDirection)
    :QGraphicsPixmapItem{parent}
{
    setPixmap(QPixmap(":/img/Player1_Up.png").scaled(80,80));
    setPos(100,100);
}

void Tank::setDirection(int Direction)
{
    tankDirection = Direction;
}

int Tank::getDirection()
{
    return tankDirection;
}
