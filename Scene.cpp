#include "Scene.h"
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>

Scene::Scene(QGraphicsScene *parent)
    : QGraphicsScene{parent},tank(new Tank)
{

    score=0;
    bestScore=0;
    addItem(tank);
    showMap();

}
void Scene::startGame()
{

}


void Scene::showPauseGraphics()
{
//pause();
scoreTextItem = new QGraphicsTextItem();
QString htmlString =   "<p> Pause <br>"
                       "<p> Score : " + QString::number(score) + " <br>"
                     + " Best Score : " + QString::number(bestScore) + " </p>"
                     + "<p> Press Enter to resume <br>";
QFont font("Consolas", 30, QFont::Bold);

scoreTextItem->setHtml(htmlString);
scoreTextItem->setFont(font);
scoreTextItem->setDefaultTextColor(Qt::blue);
addItem(scoreTextItem);

scoreTextItem->setPos(QPoint(0,0) -
                      QPoint(scoreTextItem->boundingRect().width()/2,
                             scoreTextItem->boundingRect().height()/2));
}

void Scene::hidePauseGraphics()
{
//play();
    scoreTextItem->setParentItem(nullptr);
    removeItem(scoreTextItem);
    delete scoreTextItem;
    scoreTextItem = nullptr;

}

void Scene::gameOverGSraphics()
{
while(1){
    int i=0;
    if(scoreArray[i]>0){scoreArray[i]=score;break;}
    i++;
}
gameOverItem = new QGraphicsTextItem();
QString htmlString =   "<p> Game Over <br>"
                     "<p> Score : " + QString::number(score) + " <br>"
                     + " Best Score : " + QString::number(bestScore) + " </p>"
                     + "<p> Press R to return to main menu <br>";
QFont font("Consolas", 30, QFont::Bold);

gameOverItem->setHtml(htmlString);
gameOverItem->setFont(font);
gameOverItem->setDefaultTextColor(Qt::blue);
addItem(scoreTextItem);

scoreTextItem->setPos(QPoint(0,0) -
                      QPoint(gameOverItem->boundingRect().width()/2,
                             -gameOverItem->boundingRect().height()/2));

}

void Scene::showMap()
{
    int j=0;
    int k=0;
    for(int i=0;i<=800;i+=40){

    Obstacle *j = new Obstacle();
    j->setPos(-400+i,260);
    addItem(j);
    j++;
    Obstacle *k = new Obstacle();
    k->setPos(-400+i,-300);
    addItem(k);
    k++;

    }

}
//void Scene::pause()
//{
//enemy->freeze();
//bullet->freeze();

//}

//void Scene::play()
//{
//enemy->unfreeze();
//bullet->unfreeze();

//}

void Scene::keyPressEvent(QKeyEvent *event)
{

int dir=tank->getDirection();
if (event->key() == Qt::Key_Escape) {
    showPauseGraphics();
}
if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
    hidePauseGraphics();
}

QGraphicsScene::keyPressEvent(event);

//tank move
QPointF pos = tank->pos();
if(event->key()==Qt::Key_Left&&pos.x()>-400){
    tank->moveBy(-10,0);
    tank->setDirection(3);
}
if(event->key()==Qt::Key_Right&&pos.x()<320){
    tank->moveBy(10,0);
    tank->setDirection(1);
}
if(event->key()==Qt::Key_Up&&pos.y()>-300){
    tank->moveBy(0,-10);
    tank->setDirection(0);
}
if(event->key()==Qt::Key_Down&&pos.y()<220){
    tank->moveBy(0,10);
    tank->setDirection(2);
}
if(event->key()==Qt::Key_Space){
    Bullet *bullet = new Bullet(nullptr,nullptr,dir);
    bullet->setPos(pos+QPoint(20,0));
    addItem(bullet);
}
}

void Scene::incrementScore()
{
score++;
if (score > bestScore) {
    bestScore = score;
    }
}
