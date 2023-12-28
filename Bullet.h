#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QWidget>
#include<QGraphicsRectItem>
#include<QTimer>
#include<Tank.h>

class Bullet : public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit Bullet(QObject *parent = nullptr,QGraphicsRectItem *parent_1 = nullptr,int bulletDirection=0);
    ~Bullet();
public slots:
    void shot();
signals:
    void  bulletHitsEnemv();
private:
    QTimer *timer;
    int BulletDirection;//up=0,right=1 down=2 left=4
};

#endif // BULLET_H
