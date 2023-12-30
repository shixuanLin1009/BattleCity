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
class Tree:public Obstacle
{
public:
    Tree();
};
class Steel:public Obstacle
{
public:
    Steel();
};



#endif // OBSTACLE_H
