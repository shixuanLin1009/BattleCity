#include "Scene.h"
#include "Enemy.h"
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>

Scene::Scene(QGraphicsScene *parent)
    : QGraphicsScene{parent},tank(new Tank)
{

    score=0;
    bestScore=0;
    addItem(tank);
    spawnEnemies();
    moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &Scene::updateEnemies);
    moveTimer->start(200); // Update every 200 milliseconds
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

void Scene::spawnEnemies() {
Enemy *enemy1 = new Enemy(3);
enemy1->setPos(width() - 200, 100);
addItem(enemy1);
enemies.append(enemy1);

Enemy *enemy2 = new Enemy(4);
enemy2->setPos(width() - 100, 150);
addItem(enemy2);
enemies.append(enemy2);

}


void Scene::updateEnemies() {
for (auto *enemy : enemies) {
    enemy->move();
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
if(event->key()==Qt::Key_8){
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
