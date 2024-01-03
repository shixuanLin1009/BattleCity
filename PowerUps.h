#ifndef POWERUPS_H
#define POWERUPS_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
//#include "Scene.h" 不能用 相互 Include

enum PowerUpType {
    Grenade,
    Heart,
    Helmet,
    Shovel,
    Star,
    Timer
};

class Scene; //前項聲明

class PowerUps : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    PowerUps(PowerUpType type, QGraphicsItem *parent = nullptr);
    void applyPowerUpEffect();

public slots:
    void collisionWithTank();

private:
    PowerUpType powerUpType;

    //different effects of PowerUps
    void applyGrenadeEffect();
    void applyHelmetEffect();
    void applyStarEffect();
    void applyHeartEffect();
    void applyTimerEffect();
    void applyShovelEffect();

    QTimer *timer;
    //Scene *scene;

private slots:
    void removePowerUp();

signals:
    void temp();
    void tankHitPowerUp(PowerUps *powerUp);
};

#endif // POWERUPS_H
