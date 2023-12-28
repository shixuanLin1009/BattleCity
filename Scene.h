#ifndef SCENE_H
#define SCENE_H

#include<QGraphicsScene>
#include<Tank.h>
#include <QTimer>

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
//    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // SCENE_H
