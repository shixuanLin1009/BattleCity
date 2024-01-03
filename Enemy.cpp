#include "Enemy.h"
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QTimer>
#include<QList>
#include"Obstacle.h"
#include<Scene.h>


Enemy::Enemy(int type,QObject *parent_1,QGraphicsPixmapItem *parent_2)
    : QObject {parent_1},QGraphicsPixmapItem{parent_2},enemyType(type)
{

    QPixmap originalPixmap;
    moveTimer= new QTimer();
    connect(moveTimer,&QTimer::timeout,this,&Enemy::move);
    moveTimer->start(500);

    shootTimer = new QTimer();
    connect(shootTimer,&QTimer::timeout,this,&Enemy::shoot);
    shootTimer->start(700);

    int unit =40;
    //四種敵人之參數
    switch (enemyType) {
    case 1:
        originalPixmap.load(":/Enemy/NormalTank.png");
        health = 1;
        speed = 2*unit;
        break;
    case 2:
        originalPixmap.load(":/Enemy/FastTank.png");
        health = 1;
        speed = 3*unit;
        break;
    case 3:
        originalPixmap.load(":/Enemy/PowerTank.png");
        health = 2;
        speed = 2*unit;
        break;
    case 4:
        originalPixmap.load(":/Enemy/ArmorTank.png");
        health = 3;
        speed = 1*unit;
        break;
    default:
        originalPixmap.load(":/Enemy/NormalTank.png"); // 默認
        speed = 1; // 默認
    }

    QPixmap scaledPixmap = originalPixmap.scaled(40, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    setPixmap(scaledPixmap);

}

Enemy::~Enemy()
{
    delete moveTimer;
    delete parent();
}

void Enemy::shoot()
{

    Bullet *bullet=new EnemyBullet(nullptr,nullptr,Dir);
    bullet->setPos(this->pos());
    scene()->addItem(bullet);
    connect(bullet, &EnemyBullet::bulletHitsTank, this, &Enemy::enemyWin);
    connect(bullet,&Bullet::bulletHitsBase,this,&Enemy::enemyWin);
}

void Enemy::move() {
    // Logic for enemy movement
    QPointF pos = this->pos();
    RandomDirection();
    switch (direction) {
    case Up: moveBy(0,-40); break;
    case Down: moveBy(0,40); break;
    case Left: moveBy(-40,0); break;
    case Right: moveBy(40,0); break;
    }
    //checkBounds();

    QList <QGraphicsItem*> colliding_items = collidingItems();

    for(int i = 0,n =colliding_items.size();i<n;i++){
        if (typeid (*colliding_items[i]) == typeid(Obstacle)){
            setPos(pos);
            return;
        }
        if (typeid (*colliding_items[i]) == typeid(Tank)){
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            qDebug() <<"Bullet deleted";
            qDebug() <<"Enemy deleted";
            return;
            return;
        }
    }

}
void Enemy::pause(){
    moveTimer->stop();
    shootTimer->stop();
}
void Enemy::play(){
    moveTimer->start(1000);
    shootTimer->start(500);
}
void Enemy::RandomDirection() {
    int randomDirection = QRandomGenerator::global()->bounded(0, 4);
    direction = static_cast<Direction>(randomDirection);
    Dir=randomDirection;
}


void Enemy::checkBounds() {
}


int Enemy::getType() const {
    return enemyType;
}

void Enemy::setSpeed(int newSpeed) {
    speed = newSpeed;
}

int Enemy::getSpeed() const {
    return speed;
}

void Enemy::setEnemyPixmap(const QPixmap &pixmap) {
    setPixmap(pixmap.scaled(40, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}


void Enemy::setDirection(Direction newDirection) {
    direction = newDirection;
}

Enemy::Direction Enemy::getDirection() const {
    return direction;
}

void Enemy::takeDamage(int damage) {
    health -= damage;
    if (health <= 0) {
        if (scene()) {
            scene()->removeItem(this);
            delete this;
        }
    }
}
void Enemy::enemyWin() {
    qDebug() << "Tank destroyed";
    emit tankDestroyed();
}
