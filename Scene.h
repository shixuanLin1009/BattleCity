#ifndef SCENE_H
#define SCENE_H

#include "Obstacle.h"
#include<QGraphicsScene>
#include<Tank.h>
#include<Enemy.h>
#include <QTimer>
#include<Bullet.h>

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
signals:


private:
    void pause();
    void play();
    void showMap();
    void showPauseGraphics();
    void hidePauseGraphics();
    void gameOverGSraphics();
    QGraphicsPixmapItem *gameOverPix;
    QGraphicsTextItem *scoreTextItem;
    QGraphicsTextItem *gameOverItem;
    QTimer *moveTimer;
    QList<Enemy*> enemies;
    int option;
    int scoreArray[1000];
    int score;
    int bestScore;
protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // SCENE_H
