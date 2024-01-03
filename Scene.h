#ifndef SCENE_H
#define SCENE_H

#include<QGraphicsScene>
#include<Tank.h>
#include<Enemy.h>
#include <QTimer>
#include<Bullet.h>
#include<Base.h>
#include <QWidget>

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(int option, QGraphicsScene *parent = nullptr);
    Tank *tank;
    Tank *tank2;
    void startGame();
    void incrementScore();
    void spawnEnemies();
    void updateEnemies();
    void tankDestroyed();
    bool checkCollisionWithObstacles(QGraphicsItem *item);
public slots:
    void handlePowerUpCollision(PowerUps *powerUp);
signals:
    void gamePause();
    void gamePlay();

private:
    bool pause;
    void play();
    void showMap();
    void showPauseGraphics();
    void hidePauseGraphics();
    void gameOverGraphics();
    void updateStats(const QString &filePath);
    void showBase();
    void saveScoresToFile(const QString &filePath);
    void showIce();
    void showWater();
    QGraphicsPixmapItem *gameOverPix;
    QGraphicsTextItem *scoreTextItem;
    QGraphicsTextItem *gameOverItem;
    QTimer *moveTimer;
    QTimer *spawnTimer;
    QTimer *powerUpTimer;
    QList<Enemy*> enemies;
    Base *base;
    int option;
    int totalEnemy=0;
    int scoreArray[1000];
    int score;
    int bestScore;
    int tank_destroyed;
    // 添加以下声明
private slots:
    void spawnPowerUp();

protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // SCENE_H
