#include "Bullet.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include<Obstacle.h>
#include<Enemy.h>
#include<QList>
#include<Tank.h>
#include <Scene.h>
#include<Base.h>
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
    check_colliding_items();
    /*if(x()<-400||x()>400||y()>300||y()<-300){
            scene()->removeItem(this);
            delete this;
            qDebug() <<"Bullet deleted";
    }*/
}

void Bullet::check_colliding_items()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0; i < colliding_items.size(); i++) {
            if (typeid(*colliding_items[i]) == typeid(Obstacle)) {
                Obstacle *obstacle = dynamic_cast<Obstacle *>(colliding_items[i]);
                if (obstacle)
                    obstacle->takeDamage(1); // 减少生命值
                scene()->removeItem(this);
                delete this;
                qDebug() << "Bullet deleted";
                return;
            }
            if (typeid(*colliding_items[i]) == typeid(Steel)) {
                Steel *steel = dynamic_cast<Steel *>(colliding_items[i]);
                if (steel)
                    steel->takeDamage(1); // 减少 Steel 生命值
                scene()->removeItem(this);
                delete this;
                qDebug() << "Bullet deleted";
                return;
            }
            if (typeid(*colliding_items[i]) == typeid(Stone)) {
                Stone *stone = dynamic_cast<Stone *>(colliding_items[i]);
                if (stone)
                    stone->takeDamage(1); // 减少 Stone 生命值
                scene()->removeItem(this);
                delete this;
                qDebug() << "Bullet deleted";
                return;
            }
            if (typeid(*colliding_items[i]) == typeid(Enemy)) {
                Enemy *enemy = dynamic_cast<Enemy *>(colliding_items[i]);
                if (enemy)
                    enemy->takeDamage(1); // 减少 EnemyTank 生命值
                emit bulletHitsEnemv();
                scene()->removeItem(this);
                delete this;
                qDebug() << "Bullet deleted";
                qDebug() << "Enemy deleted";
                return;
            }
            // Base一擊必殺
            if (typeid (*colliding_items[i]) == typeid(Base)){
                emit bulletHitsBase();
                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);
                //delete colliding_items[i];
                delete this;
                qDebug() <<"Bullet deleted";
                qDebug() <<"Tank deleted";
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
    check_colliding_items();

}


void EnemyBullet::check_colliding_items()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0; i < colliding_items.size(); i++) {
            if (typeid(*colliding_items[i]) == typeid(Obstacle)) {
                Obstacle *obstacle = dynamic_cast<Obstacle *>(colliding_items[i]);
                if (obstacle)
                    obstacle->takeDamage(1); // 减少生命值
                scene()->removeItem(this);
                delete this;
                qDebug() << "EnemyBullet deleted";
                return;
            }
            if (typeid(*colliding_items[i]) == typeid(Steel)) {
                Steel *steel = dynamic_cast<Steel *>(colliding_items[i]);
                if (steel)
                    steel->takeDamage(1); // 减少 Steel 生命值
                scene()->removeItem(this);
                delete this;
                qDebug() << "EnemyBullet deleted";
                return;
            }
            if (typeid(*colliding_items[i]) == typeid(Stone)) {
                Stone *stone = dynamic_cast<Stone *>(colliding_items[i]);
                if (stone)
                    stone->takeDamage(1); // 减少 Stone 生命值
                scene()->removeItem(this);
                delete this;
                qDebug() << "EnemyBullet deleted";
                return;
            }
            if (typeid(*colliding_items[i]) == typeid(Tank)) {
                emit bulletHitsTank();
                Tank *tank = dynamic_cast<Tank *>(colliding_items[i]);
                if (tank)
                    tank->takeDamage(1); // 减少 PlayerTank 生命值
                scene()->removeItem(this);
                delete this;
                qDebug() << "EnemyBullet deleted";
                qDebug() << "Tank deleted";
                return;
            }
            // Base一擊必殺
            if (typeid (*colliding_items[i]) == typeid(Base)){
                emit bulletHitsBase();
                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);
                //delete colliding_items[i];
                delete this;
                qDebug() <<"Bullet deleted";
                qDebug() <<"Tank deleted";
                return;
            }
    }
}

