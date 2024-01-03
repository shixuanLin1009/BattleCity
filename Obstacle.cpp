#include "Obstacle.h"

Obstacle::Obstacle(QGraphicsPixmapItem *parent)
    :QGraphicsPixmapItem(parent), health(1000)
{
    // 邊界石
    setPixmap(QPixmap(":/Obstacles/Bedrock.png").scaled(40,40));

}

void Obstacle::takeDamage(int damage) {
    health -= damage;
    if (health <= 0) {
        if (scene()) {
            scene()->removeItem(this); // Obstacles血量檢測
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
    // Trees 二選一
    int randomIndex = QRandomGenerator::global()->bounded(2); // 生成 0 或 1
    if(randomIndex == 0) {
        // 第一種 Tree
        setPixmap(QPixmap(":/Obstacles/Tree_1.png").scaled(40, 40));
    } else {
        // 第二種 Tree
        setPixmap(QPixmap(":/Obstacles/Tree_2.png").scaled(40, 40));
    }
}

// Stone health = 3
Stone::Stone(QGraphicsPixmapItem *parent) : Obstacle(parent) {
    health = 3;
    setPixmap(QPixmap(":/Obstacles/Stone.png").scaled(40,40));
}

// Steel health = 6
Steel::Steel(QGraphicsPixmapItem *parent) : Obstacle(parent) {
    health = 6;
    setPixmap(QPixmap(":/Obstacles/Steel.png").scaled(40,40));
}

Ice::Ice()
{
    setPixmap(QPixmap(":/Obstacles/Ice.png").scaled(40,40));
}


