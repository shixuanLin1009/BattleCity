#ifndef POWERUPS_H
#define POWERUPS_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

enum PowerUpType {
    Grenade,
    Heart,
    Helmet,
    Shovel,
    Star,
    Timer
};

class PowerUps : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    PowerUps(PowerUpType type, QGraphicsItem *parent = nullptr);

public slots:
    void collisionWithTank();

private:
    PowerUpType powerUpType;

    void applyPowerUpEffect();

    //different effects of PowerUps
    void applyGrenadeEffect();
    void applyHelmetEffect();
    void applyStarEffect();
    void applyHeartEffect();
    void applyTimerEffect();
    void applyShovelEffect();

    QTimer *timer;

private slots:
    void removePowerUp();

signals:
    void temp();
    void tankHitPowerUp(PowerUps *powerUp);
};

#endif // POWERUPS_H
