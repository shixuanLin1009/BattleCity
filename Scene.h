#ifndef SCENE_H
#define SCENE_H

#include<QGraphicsScene>
#include<Tank.h>

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QGraphicsScene *parent = nullptr);
    Tank *tank;
signals:

};

#endif // SCENE_H
