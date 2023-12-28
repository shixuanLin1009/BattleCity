#ifndef SCENE_H
#define SCENE_H

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
signals:


    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event);
private:
};

#endif // SCENE_H
