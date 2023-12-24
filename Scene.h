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
signals:

};

#endif // SCENE_H
