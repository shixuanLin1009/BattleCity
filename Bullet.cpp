#include "Bullet.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include<Obstacle.h>
#include<Enemy.h>
#include<QList>
#include<Tank.h>
Bullet::Bullet(QObject *parent,QGraphicsPixmapItem *parent_1,int bulletDirection)
    : QObject{parent},QGraphicsPixmapItem {parent_1}
{

    timer = new QTimer();
    connect(timer,&QTimer::timeout,this,&Bullet::shot);
    timer->start(50);
    BulletDirection =bulletDirection;

}

Bullet::~Bullet()
{
    delete timer;
}
void Bullet::shot()
{
    if (BulletDirection == 0){
            moveBy(0,-10);//up
            setPixmap(QPixmap(":/img/Bullet_Up.png").scaled(40,40));
        }
    if (BulletDirection == 1){
            moveBy(10,0);//right
            setPixmap(QPixmap(":/img/Bullet_Right.png").scaled(40,40));
    }
    if (BulletDirection == 2){
            moveBy(0,10);//down
            setPixmap(QPixmap(":/img/Bullet_Down.png").scaled(40,40));
    }
    if (BulletDirection == 3){
            moveBy(-10,0);//left
            setPixmap(QPixmap(":/img/Bullet_Left.png").scaled(40,40));
    }
    check_colliding_itmes();
    /*if(x()<-400||x()>400||y()>300||y()<-300){
            scene()->removeItem(this);
            delete this;
            qDebug() <<"Bullet deleted";
    }*/
}

void Bullet::check_colliding_itmes()
{
    QList <QGraphicsItem *>  colliding_itmes = collidingItems();

    for(int i = 0,n =colliding_itmes.size();i<n;i++){

            if (typeid (*colliding_itmes[i]) == typeid(Obstacle)){
                scene()->removeItem(this);
                delete this;
                qDebug() <<"Bullet deleted";
                return;
            }
            if (typeid (*colliding_itmes[i]) == typeid(Steel)){
                scene()->removeItem(colliding_itmes[i]);
                scene()->removeItem(this);
                delete colliding_itmes[i];
                delete this;
                qDebug() <<"Bullet deleted";
                return;
            }
            if (typeid (*colliding_itmes[i]) == typeid(Enemy)){
                emit bulletHitsEnemv();
                scene()->removeItem(colliding_itmes[i]);
                scene()->removeItem(this);
                delete colliding_itmes[i];
                delete this;
                qDebug() <<"Bullet deleted";
                qDebug() <<"Enemy deleted";
                return;
            }
    }
}




EnemyBullet::EnemyBullet(QObject *parent, QGraphicsPixmapItem *parent_1, int bulletDirection)
{
    e_timer = new QTimer();
    connect(e_timer,&QTimer::timeout,this,&Bullet::shot);
    e_timer->start(50);
    Direction =bulletDirection;
}

EnemyBullet::~EnemyBullet()
{
    delete e_timer;
}

void EnemyBullet::shot()
{
    if (Direction == 0){
            moveBy(0,-10);//up
            setPixmap(QPixmap(":/img/Bullet_Up.png").scaled(40,40));
    }
    if (Direction == 1){
            moveBy(10,0);//right
            setPixmap(QPixmap(":/img/Bullet_Right.png").scaled(40,40));
    }
    if (Direction == 2){
            moveBy(0,10);//down
            setPixmap(QPixmap(":/img/Bullet_Down.png").scaled(40,40));
    }
    if (Direction == 3){
            moveBy(-10,0);//left
            setPixmap(QPixmap(":/img/Bullet_Left.png").scaled(40,40));
    }
    check_colliding_itmes();

}

void EnemyBullet::check_colliding_itmes()
{
    QList <QGraphicsItem *>  colliding_itmes = collidingItems();

    for(int i = 0,n =colliding_itmes.size();i<n;i++){

            if (typeid (*colliding_itmes[i]) == typeid(Obstacle)){
                scene()->removeItem(this);
                delete this;
                qDebug() <<"Bullet deleted";
                return;
            }
            if (typeid (*colliding_itmes[i]) == typeid(Steel)){
                scene()->removeItem(colliding_itmes[i]);
                scene()->removeItem(this);
                delete colliding_itmes[i];
                delete this;
                qDebug() <<"Bullet deleted";
                return;
            }
            if (typeid (*colliding_itmes[i]) == typeid(Tank)){
                scene()->removeItem(colliding_itmes[i]);
                scene()->removeItem(this);
                //delete colliding_itmes[i];
                delete this;
                qDebug() <<"Bullet deleted";
                qDebug() <<"Enemy deleted";
                return;
            }
    }
}
