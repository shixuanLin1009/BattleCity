#ifndef SCENE_H
#define SCENE_H

#include "Obstacle.h"
#include<QGraphicsScene>
#include<Tank.h>
#include <QTimer>
#include<Bullet.h>

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QGraphicsScene *parent = nullptr);
    Tank *tank;
    void startGame();
    void incrementScore();
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

    int scoreArray[1000];
    int score;
    int bestScore;
protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // SCENE_H
