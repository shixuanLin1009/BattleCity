#include "Scene.h"
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>

Scene::Scene(QGraphicsScene *parent)
    : QGraphicsScene{parent},tank(new Tank)
{
    addItem(tank);
}
void Scene::startGame()
{

}

void Scene::keyPressEvent(QKeyEvent *event)
{
    int dir=tank->getDirection();
    switch (event->key()) {
    case Qt::Key_Left:
        tank->moveBy(-10, 0);
        tank->setDirection(3);
        break;
    case Qt::Key_Right:
        tank->moveBy(10, 0);
        tank->setDirection(1);
        break;
    case Qt::Key_Up:
        tank->moveBy(0, -10);
        tank->setDirection(0);
        break;
    case Qt::Key_Down:
        tank->moveBy(0, 10);
        tank->setDirection(2);
        break;
    case Qt::Key_Space:
        Bullet  *bullet= new Bullet(nullptr,nullptr,dir);
        bullet->setPos(tank->x()+50,tank->y()-50);
        addItem(bullet);
    }

}
