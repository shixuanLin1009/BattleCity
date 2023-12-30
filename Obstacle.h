#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QRect>
#include <QPainter>

class Obstacle
{
public:
    Obstacle(int x, int y, int width, int height);

    // Getters
    QRect getRect() const;

    // Drawing method
    void draw(QPainter &painter) const;

private:
    QRect rect;
};

#endif // OBSTACLE_H
