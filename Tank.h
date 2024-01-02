#ifndef TANK_H
#define TANK_H

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

    int Speed() const;
    void setSpeed(int newSpeed);
public slots:
    void normal();
signals:
    void tankHitsObstacle();
    void destroyed();
private:
    void fire();
    int tankDirection;
    int m_Speed;
};

#endif // TANK_H
