#include "Scene.h"

Scene::Scene(QGraphicsScene *parent)
    : QGraphicsScene{parent},tank(new Tank)
{
    addItem(tank);
}
