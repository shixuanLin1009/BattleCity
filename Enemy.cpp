#include "Enemy.h"
//#include "Bullet.h"
#include <QGraphicsScene>
#include <QRandomGenerator>
//#include <QBrush>
#include <QTimer>

Enemy::Enemy(int type, QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent), enemyType(type) {

    QPixmap originalPixmap;
    //四種敵人之參數
    switch (enemyType) {
    case 1:
        originalPixmap.load(":/Enemy/NormalTank.png");
        health = 10;
        speed = 2;
        break;
    case 2:
        originalPixmap.load(":/Enemy/FastTank.png");
        health = 10;
        speed = 3;
        break;
    case 3:
        originalPixmap.load(":/Enemy/PowerTank.png");
        health = 20;
        speed = 2;
        break;
    case 4:
        originalPixmap.load(":/Enemy/ArmorTank.png");
        health = 40;
        speed = 1.5;
        break;
    default:
        originalPixmap.load(":/Enemy/NormalTank.png"); // 默認
        speed = 1; // 默認
    }

    QPixmap scaledPixmap = originalPixmap.scaled(40, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    setPixmap(scaledPixmap);
}

void Enemy::move() {
    // Logic for enemy movement
    RandomDirection();
    switch (direction) {
    case Up: setPos(x(), y() - speed); break;
    case Down: setPos(x(), y() + speed); break;
    case Left: setPos(x() - speed, y()); break;
    case Right: setPos(x() + speed, y()); break;
    }
    checkBounds();
}

void Enemy::RandomDirection() {
    int randomDirection = QRandomGenerator::global()->bounded(0, 4);
    direction = static_cast<Direction>(randomDirection);
}


void Enemy::checkBounds() {
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
