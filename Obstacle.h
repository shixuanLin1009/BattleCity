#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QObject>
#include <QWidget>
#include<QGraphicsPixmapItem>
#include <QGraphicsScene>

class Obstacle: public QGraphicsPixmapItem {
public:
    Obstacle(QGraphicsPixmapItem *parent = nullptr);
    virtual void takeDamage(int damage); // 處理傷害公共方法

protected:
    int health;
};

// Water
class Water: public Obstacle {
public:
    Water();
};

// Tree
class Tree: public Obstacle {
public:
    Tree();
};

// Stone
class Stone : public Obstacle {
public:
    Stone(QGraphicsPixmapItem *parent = nullptr);
    //void takeDamage(int damage) override;
};

// Steel
class Steel : public Obstacle {
public:
    Steel(QGraphicsPixmapItem *parent = nullptr);
    //void takeDamage(int damage) override;
};

class Ice:public Obstacle
{
public:
    Ice();
};


#endif // OBSTACLE_H
