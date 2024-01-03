#ifndef TANK_H
#define TANK_H

#include "PowerUps.h"
#include <QObject>
#include <QWidget>
#include<QGraphicsPixmapItem>
#include<QTimer>



class Tank:public QGraphicsPixmapItem
{
    Q_PROPERTY(int Speed READ Speed WRITE setSpeed);
public:
    Tank(QGraphicsPixmapItem *parent=nullptr);
    void setDirection(int Direction);
    int getDirection();
    void checkColliging(QPointF pos);
    void takeDamage(int damage); // 處理所受傷害
    int getSpeed() const { return Speed(); }
    void removePowerUp();
    
protected:
    int health; // 生命值
    void setSpeed(int newSpeed);
    int Speed() const;
public slots:
    void normal();
    void hitPowerUp(PowerUps *powerUp);

signals:
    void temp();
    void tankHitsObstacle();
    void tankHitPowerUp(PowerUps *powerUp);
    void destroyed();
private:
    void fire();
    int tankDirection;
    int m_Speed;
};

#endif // TANK_H
