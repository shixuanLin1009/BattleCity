#include "Obstacle.h"

Obstacle::Obstacle(QGraphicsPixmapItem *parent)
    :QGraphicsPixmapItem(parent), health(100)
{
    setPixmap(QPixmap(":/Obstacles/Bedrock.png").scaled(40,40));

}

void Obstacle::takeDamage(int damage) {
    health -= damage;
    if (health <= 0) {
        if (scene()) {
            scene()->removeItem(this); // 从场景中删除对象
            delete this;
        }
    }
}

Water::Water()
{
    setPixmap(QPixmap(":/Obstacles/Water.png").scaled(40,40));
}

Tree::Tree()
{
    setPixmap(QPixmap(":/Obstacles/Tree_1.png").scaled(40,40));
    setPixmap(QPixmap(":/Obstacles/Tree_2.png").scaled(40,40));
    setZValue(1);
}

Stone::Stone(QGraphicsPixmapItem *parent) : Obstacle(parent) {
    health = 3;
    setPixmap(QPixmap(":/Obstacles/Stone.png").scaled(40,40));
}

//void Stone::takeDamage(int damage) {
    // Stone-specific logic for taking damage
    //Obstacle::takeDamage(damage);
//}

Steel::Steel(QGraphicsPixmapItem *parent) : Obstacle(parent) {
    health = 6;
    setPixmap(QPixmap(":/Obstacles/Steel.png").scaled(40,40));
}


//void Steel::takeDamage(int damage) {
    // Steel-specific logic for taking damage
    //Obstacle::takeDamage(damage);
//}

Ice::Ice()
{
    setPixmap(QPixmap(":/Obstacles/Ice.png").scaled(40,40));
}


