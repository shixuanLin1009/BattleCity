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
    switch (event->key()) {
    case Qt::Key_Left:
        tank->moveBy(-10, 0);
        break;
    case Qt::Key_Right:
        tank->moveBy(10, 0);
        break;
    case Qt::Key_Up:
        tank->moveBy(0, -10);
        break;
    case Qt::Key_Down:
        tank->moveBy(0, 10);
        break;
    case Qt::Key_Space:
        Bullet  *bullet= new Bullet();
        bullet->setPos(tank->x(),tank->y());
        addItem(bullet);
    }

}
