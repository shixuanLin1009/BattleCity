#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QGraphicsEllipseItem>
#include <QTimer>
#include <QObject>

class Enemy : public QGraphicsPixmapItem {

public:
    enum Direction { Up, Down, Left, Right };
    explicit Enemy(int type, QGraphicsItem *parent = nullptr);

    void startShooting();
    void setEnemyPixmap(const QPixmap &pixmap);
    void move();
    int getType() const;
    void setSpeed(int newSpeed);
    int getSpeed() const;

    void setDirection(Direction newDirection);
    Direction getDirection() const;

    //public slots:
    //    void shoot();

private:
    int enemyType;
    double speed;
    int health;
    Direction direction;
    QTimer* shootTimer;
    void RandomDirection(); // If you need random direction logic
    void checkBounds();
};

#endif // ENEMY_H
