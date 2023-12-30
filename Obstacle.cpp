#include "Obstacle.h"

Obstacle::Obstacle(QGraphicsPixmapItem *parent)
    :QGraphicsPixmapItem{parent}
{
    setPixmap(QPixmap(":/img/Stone.png").scaled(40,40));

}



Tree::Tree()
{
    setPixmap(QPixmap(":/Obstacles/Tree_1.png").scaled(40,40));
}

Steel::Steel()
{
    setPixmap(QPixmap(":/Obstacles/Steel.png").scaled(40,40));
}
