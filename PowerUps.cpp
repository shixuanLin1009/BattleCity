#include "PowerUps.h"
#include "Tank.h"
#include "Obstacle.h"
#include "Enemy.h"
#include "Scene.h"
//#include "Base.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QList>
#include <QDebug>

PowerUps::PowerUps(PowerUpType type, QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent), powerUpType(type)
{
    switch (powerUpType) {
    case Grenade:
        setPixmap(QPixmap(":/PowerUps/Grenade.png").scaled(40,40));
        break;

    case Heart:
        setPixmap(QPixmap(":/PowerUps/Heart.png").scaled(40,40));
        break;

    case Helmet:
        setPixmap(QPixmap(":/PowerUps/Helmet.png").scaled(40,40));
        break;

    case Shovel:
        setPixmap(QPixmap(":/PowerUps/Shovel.png").scaled(40,40));
        break;

    case Star:
        setPixmap(QPixmap(":/PowerUps/Star.png").scaled(40,40));
        break;

    case Timer:
        setPixmap(QPixmap(":/PowerUps/Timer.png").scaled(40,40));
        break;

    default:
        break; // 默認
    }

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &PowerUps::removePowerUp);
    timer->start(7000); // 7秒移除未使用之 Powerup
}

// PowerUps效果設置
void PowerUps::applyPowerUpEffect()
{
    switch (powerUpType) {
    case Grenade:
        // Destroy all enemies currently on the screen
        applyGrenadeEffect();
        break;
    case Helmet:
        // Give the player a temporary shield
        applyHelmetEffect();
        break;
    case Star:
        // Make the tank's bullets lethal to enemies
        applyStarEffect();
        break;
    case Heart:
        // Give the player an extra life
        applyHeartEffect();
        break;
    case Timer:
        // Freeze the movement of enemies
        applyTimerEffect();
        break;
    case Shovel:
        // Make walls around the Base invincible
        applyShovelEffect();
        break;
    }
}


void PowerUps::removePowerUp()
{
    // 移除 PowerUp
    scene()->removeItem(this);
    delete this;
}

void PowerUps::collisionWithTank() {
    emit tankHitPowerUp(this);
}


void PowerUps::applyGrenadeEffect() {}
void PowerUps::applyHeartEffect() {}
void PowerUps::applyHelmetEffect() {}
void PowerUps::applyStarEffect() {
    Scene* currentScene = dynamic_cast<Scene*>(this->scene());
    if (currentScene) {
        for (int i = 0; i < 5; ++i) {
            currentScene->incrementScore(); // 调用 Scene 的 incrementScore 方法
        }
    }
}
void PowerUps::applyTimerEffect() {}
void PowerUps::applyShovelEffect() {}

/*
void PowerUps::applyGrenadeEffect() {
    QList<QGraphicsItem *> items = scene()->items();
    for (auto *item : items) {
        Enemy *enemy = dynamic_cast<Enemy *>(item);
        if (enemy) {
            enemy->takeDamage(enemy->getHealth()); // 摧毀敵人
        }
    }
}


void PowerUps::applyHeartEffect() {
    Tank *playerTank = dynamic_cast<Tank *>(scene()->playerTank());
    if (playerTank) {
        playerTank->addLife(); // 增加一條生命
    }
}


void PowerUps::applyHelmetEffect() {
    Tank *playerTank = dynamic_cast<Tank *>(scene()->playerTank());
    if (playerTank) {
        playerTank->setShield(true);
        QTimer::singleShot(10000, playerTank, [playerTank]() {
            playerTank->setShield(false); // 10秒後取消護盾
        });
    }
}


void PowerUps::applyStarEffect() {
    Tank *playerTank = dynamic_cast<Tank *>(scene()->playerTank());
    if (playerTank) {
        playerTank->setLethalBullets(true);
        QTimer::singleShot(10000, playerTank, [playerTank]() {
            playerTank->setLethalBullets(false); // 10秒後取消致命子彈狀態
        });
    }
}



void PowerUps::applyTimerEffect() {
    QList<QGraphicsItem *> items = scene()->items();
    for (auto *item : items) {
        Enemy *enemy = dynamic_cast<Enemy *>(item);
        if (enemy) {
            enemy->setFrozen(true); // 凍結敵人
        }
    }

    QTimer::singleShot(10000, this, [=]() {
        for (auto *item : items) {
            Enemy *enemy = dynamic_cast<Enemy *>(item);
            if (enemy) {
                enemy->setFrozen(false); // 解凍敵人
            }
        }
    });
}

void PowerUps::applyShovelEffect() {
    QList<QGraphicsItem *> items = scene()->items();
    for (auto *item : items) {
        Obstacle *obstacle = dynamic_cast<Obstacle *>(item);
        if (obstacle) {
            obstacle->setInvincible(true); // 使障礙物無敵
        }
    }

    QTimer::singleShot(10000, this, [=]() {
        for (auto *item : items) {
            Obstacle *obstacle = dynamic_cast<Obstacle *>(item);
            if (obstacle) {
                obstacle->setInvincible(false); // 取消無敵
            }
        }
    });
}
*/


