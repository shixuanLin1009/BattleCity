#include "Tank.h"

Tank::Tank(QGraphicsRectItem *parent ,int tankDirection)
    :QGraphicsRectItem{parent}
{
    setRect(100,-100,100,100);
}

void Tank::setDirection(int Direction)
{
    tankDirection = Direction;
}

int Tank::getDirection()
{
    return tankDirection;
}
