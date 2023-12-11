#include "Tank.h"

Tank::Tank(QGraphicsRectItem *parent)
:QGraphicsRectItem{parent}
{
    setRect(200,-100,100,100);
}
