#include "Enemy.h"
//#include "Bullet.h"
#include <QGraphicsScene>
#include <QRandomGenerator>
//#include <QBrush>
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
    moveTimer->start(1000);

    shootTimer = new QTimer();
    connect(shootTimer,&QTimer::timeout,this,&Enemy::shoot);
    shootTimer->start(500);

    int unit =40;
    //四種敵人之參數
    switch (enemyType) {
    case 1:
        originalPixmap.load(":/Enemy/NormalTank.png");
        health = 10;
        speed = 2*unit;
        break;
    case 2:
        originalPixmap.load(":/Enemy/FastTank.png");
        health = 10;
        speed = 3*unit;
        break;
    case 3:
        originalPixmap.load(":/Enemy/PowerTank.png");
        health = 20;
        speed = 2*unit;
        break;
    case 4:
        originalPixmap.load(":/Enemy/ArmorTank.png");
        health = 40;
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

    QList <QGraphicsItem*> colliding_itmes = collidingItems();

    for(int i = 0,n =colliding_itmes.size();i<n;i++){
        if (typeid (*colliding_itmes[i]) == typeid(Obstacle)){
            setPos(pos);
            return;
        }
    }


}

void Enemy::RandomDirection() {
    int randomDirection = QRandomGenerator::global()->bounded(0, 3);
    direction = static_cast<Direction>(randomDirection);
    Dir=randomDirection;
}


void Enemy::checkBounds() {
    /*
    QRectF sceneBounds = scene()->sceneRect();
    qreal halfWidth = pixmap().width() / 2.0;
    qreal halfHeight = pixmap().height() / 2.0;
    qreal tolerance = 10; // Tolerance value for collision detection

    // Check left and right bounds with tolerance
    if (x() - halfWidth < sceneBounds.left() + tolerance) {
        setPos(sceneBounds.left() + halfWidth + tolerance, y());
        RandomDirection();
    } else if (x() + halfWidth > sceneBounds.right() - tolerance) {
        setPos(sceneBounds.right() - halfWidth - tolerance, y());
        RandomDirection();
    }

    // Check top and bottom bounds with tolerance
    if (y() - halfHeight < sceneBounds.top() + tolerance) {
        setPos(x(), sceneBounds.top() + halfHeight + tolerance);
        RandomDirection();
    } else if (y() + halfHeight > sceneBounds.bottom() - tolerance) {
        setPos(x(), sceneBounds.bottom() - halfHeight - tolerance);
        RandomDirection();
    }
    */
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
