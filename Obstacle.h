#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QObject>
#include <QWidget>
#include<QGraphicsPixmapItem>
class Obstacle:public QGraphicsPixmapItem
{
public:
    Obstacle(QGraphicsPixmapItem *parent=nullptr);
};

#endif // OBSTACLE_H
