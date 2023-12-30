#include "Scene.h"
#include "Enemy.h"
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include<QRandomGenerator>

Scene::Scene(int opt, QGraphicsScene *parent)
    : QGraphicsScene{parent},tank(new Tank)
{

    score=0;
    bestScore=0;
    addItem(tank);
    spawnTimer = new QTimer();
    connect(spawnTimer,&QTimer::timeout,this,&Scene::spawnEnemies);
    spawnTimer->start(4000);
    spawnEnemies();
    moveTimer = new QTimer();
    connect(moveTimer, &QTimer::timeout, this, &Scene::updateEnemies);
    moveTimer->start(200); // Update every 200 milliseconds

    tank->setPos(0,220);
    if(opt==1){
        option=opt;
        tank2 = new Tank();
        addItem(tank2);
        tank2->setPos(-40,220);
    }
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

void Scene::showBase()
{
    base = new Base();
    base->setPos(-40,60);
    addItem(base);
    //橫的第一列
    for(int i=0;i<=3;i++)
    {
        Steel *j =new Steel();
        j->setPos(-80+40*i,20);
        addItem(j);
        j++;
    }
    //橫的第二列
    for(int i=0;i<=2;i++)
    {
        Steel *j =new Steel();
        j->setPos(-80+40*i,100);
        addItem(j);
        j++;
    }
    //直的第一列
    for(int i=0;i<=1;i++)
    {
        Steel *j =new Steel();
        j->setPos(-80,60+40*i);
        addItem(j);
        j++;
    }
    //直的第二列
    for(int i=0;i<=1;i++)
    {
        Steel *j =new Steel();
        j->setPos(40,60+40*i);
        addItem(j);
        j++;
    }
}


void Scene::spawnEnemies() {
    int ran= QRandomGenerator::global()->bounded(0, 4);
    int ran_2= QRandomGenerator::global()->bounded(0, 4);
    Enemy *enemy1 = new Enemy(ran);
    enemy1->setPos(-240, -260);
    addItem(enemy1);

    Enemy *enemy2 = new Enemy(ran_2);
    enemy2->setPos(240, -220);
    addItem(enemy2);

}


void Scene::updateEnemies() {
for (auto *enemy : enemies) {
    enemy->move();
}
}
void Scene::showMap()
{
    showBase();
    for(int i=0;i<=240;i+=40){

        Tree *a = new Tree();
        a->setPos(-400+i,-60);
        addItem(a);
        a++;

    }
    for(int i=0;i<=760;i+=40){

        Obstacle *j = new Obstacle();
        j->setPos(-400+i,260);
        addItem(j);
        j++;
        Obstacle *k = new Obstacle();
        k->setPos(-400+i,-300);
        addItem(k);
        k++;

    }

    for(int i=0;i<=560;i+=40){

        Obstacle *j = new Obstacle();
        j->setPos(-400,-300+i);
        addItem(j);
        j++;
        Obstacle *k = new Obstacle();
        k->setPos(360,-300+i);
        addItem(k);
        k++;

    }

    for(int i=0;i<=680;i+=120){

        Obstacle *j = new Obstacle();
        j->setPos(-320+i,-220);
        addItem(j);
        j++;
        Obstacle *k = new Obstacle();
        k->setPos(-320+i,-180);
        addItem(k);
        k++;
        Obstacle *l = new Obstacle();
        l->setPos(-320+i,-140);
        addItem(l);
        l++;
        Obstacle *m = new Obstacle();
        m->setPos(-320+i,-100);
        addItem(m);
        m++;
    }

    for(int i=0;i<=120;i+=120){

        Obstacle *j = new Obstacle();
        j->setPos(-320+i,60);
        addItem(j);
        j++;
        Obstacle *k = new Obstacle();
        k->setPos(-320+i,100);
        addItem(k);
        k++;
        Obstacle *l = new Obstacle();
        l->setPos(-320+i,140);
        addItem(l);
        l++;
        Obstacle *m = new Obstacle();
        m->setPos(-320+i,180);
        addItem(m);
        m++;
    }

    for(int i=0;i<=120;i+=120){

        Obstacle *j = new Obstacle();
        j->setPos(160+i,60);
        addItem(j);
        j++;
        Obstacle *k = new Obstacle();
        k->setPos(160+i,100);
        addItem(k);
        k++;
        Obstacle *l = new Obstacle();
        l->setPos(160+i,140);
        addItem(l);
        l++;
        Obstacle *m = new Obstacle();
        m->setPos(160+i,180);
        addItem(m);
        m++;
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
QPointF pos=tank->pos();
int step=20;
if(event->key()==Qt::Key_Left&&pos.x()>-400){
    tank->moveBy(-step,0);
    tank->setDirection(3);
    tank->setPixmap(QPixmap(":/img/Player1_Left.png").scaled(40,40));
    tank->checkColliging(pos);
}
if(event->key()==Qt::Key_Right&&pos.x()<320){
    tank->moveBy(step,0);
    tank->setDirection(1);
    tank->setPixmap(QPixmap(":/img/Player1_Right.png").scaled(40,40));
    tank->checkColliging(pos);
}
if(event->key()==Qt::Key_Up&&pos.y()>-300){
    tank->moveBy(0,-step);
    tank->setDirection(0);
    tank->setPixmap(QPixmap(":/img/Player1_Up.png").scaled(40,40));
    tank->checkColliging(pos);
}
if(event->key()==Qt::Key_Down&&pos.y()<220){
    tank->moveBy(0,step);
    tank->setDirection(2);
    tank->setPixmap(QPixmap(":/img/Player1_Down.png").scaled(40,40));
    tank->checkColliging(pos);
}
if(event->key()==Qt::Key_Space){
    Bullet *bullet = new Bullet(nullptr,nullptr,dir);
    connect(bullet,&Bullet::bulletHitsEnemv,this,&Scene::incrementScore);
    bullet->setPos(pos);
    addItem(bullet);
}
if(option==1){
    int dir2=tank2->getDirection();
    QPointF pos2=tank2->pos();
    if(event->key()==Qt::Key_A&&pos2.x()>-400){
        tank2->moveBy(-10,0);
        tank2->setDirection(3);
        tank2->setPixmap(QPixmap(":/img/Player1_Left.png").scaled(40,40));
        tank2->checkColliging(pos2);
    }
    if(event->key()==Qt::Key_D&&pos2.x()<320){
        tank2->moveBy(10,0);
        tank2->setDirection(1);
        tank2->setPixmap(QPixmap(":/img/Player1_Right.png").scaled(40,40));
        tank2->checkColliging(pos2);
    }
    if(event->key()==Qt::Key_W&&pos2.y()>-300){
        tank2->moveBy(0,-10);
        tank2->setDirection(0);
        tank2->setPixmap(QPixmap(":/img/Player1_Up.png").scaled(40,40));
        tank2->checkColliging(pos2);
    }
    if(event->key()==Qt::Key_S&&pos2.y()<220){
        tank2->moveBy(0,10);
        tank2->setDirection(2);
        tank2->setPixmap(QPixmap(":/img/Player1_Down.png").scaled(40,40));
        tank2->checkColliging(pos2);
    }
    if(event->key()==Qt::Key_F){
        Bullet *bullet2 = new Bullet(nullptr,nullptr,dir2);
        connect(bullet2,&Bullet::bulletHitsEnemv,this,&Scene::incrementScore);
        bullet2->setPos(pos2);
        addItem(bullet2);
    }

}
QGraphicsScene::keyPressEvent(event);
}

void Scene::incrementScore()
{
score++;
if (score > bestScore) {
    bestScore = score;
    }
}
