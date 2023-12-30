#include "obstacle.h"

Obstacle::Obstacle(int x, int y, int width, int height)
    : rect(x, y, width, height)
{
    // Additional initialization if needed
}

QRect Obstacle::getRect() const
{
    return rect;
}

void Obstacle::draw(QPainter &painter) const
{
    // Draw a simple rectangle to represent the obstacle
    painter.fillRect(rect, Qt::gray);
    painter.drawRect(rect);
}
