#ifndef SCENE_H
#define SCENE_H

#include "Obstacle.h"
#include<QGraphicsScene>
#include<Tank.h>
#include<Enemy.h>
#include <QTimer>
#include<Bullet.h>
#include<Base.h>

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
    void gameOverGSraphics();
    void tankDestroyed();
signals:
    void gamePause();
    void gamePlay();

private:
    bool pause;
    void play();
    void showMap();
    void showPauseGraphics();
    void hidePauseGraphics();
    void gameOverGSraphics();
    void showBase();
    QGraphicsPixmapItem *gameOverPix;
    QGraphicsTextItem *scoreTextItem;
    QGraphicsTextItem *gameOverItem;
    QTimer *moveTimer;
    QTimer *spawnTimer;
    QList<Enemy*> enemies;
    Base *base;
    int option;
    int scoreArray[1000];
    int score;
    int bestScore;
    int tank_destroyed;
protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // SCENE_H
