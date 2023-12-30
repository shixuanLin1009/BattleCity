#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QGraphicsEllipseItem>
#include <QTimer>
#include <QObject>
#include<QWidget>
#include<Bullet.h>

class Enemy : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:

    explicit Enemy(int type = 0,QObject *parent_1 = nullptr, QGraphicsPixmapItem *parent_2 = nullptr);
    ~Enemy();

    enum Direction { Up, Down, Left, Right };
    void setEnemyPixmap(const QPixmap &pixmap);
    void move();
    int getType() const;
    void setSpeed(int newSpeed);
    int getSpeed() const;

    void setDirection(Direction newDirection);
    Direction getDirection() const;

public slots:
    void shoot();

private:
    int enemyType;
    double speed;
    int health;
    Direction direction;
    int Dir;
    QTimer *moveTimer;
    QTimer *shootTimer;
    void RandomDirection(); // If you need random direction logic
    void checkBounds();
};

#endif // ENEMY_H
