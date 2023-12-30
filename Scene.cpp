#include "Scene.h"
#include "Enemy.h"
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>

Scene::Scene(int opt, QGraphicsScene *parent)
    : QGraphicsScene{parent},tank(new Tank)
{
    pause=false;
    option=opt;
    score=0;
    bestScore=0;
    tank_destroyed=0;
    addItem(tank);

    spawnEnemies();
    moveTimer = new QTimer(this);
    moveTimer->start(200); // Update every 200 milliseconds

    tank->setPos(0,220);

    if(opt==1){

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
//while(1){
//    int i=0;
//    if(scoreArray[i]>0){scoreArray[i]=score;break;}
//    i++;
//}
gameOverItem = new QGraphicsTextItem();
QString htmlString =   "<p> Game Over <br>"
                     "<p> Score : " + QString::number(score) + " <br>"
                     + " Best Score : " + QString::number(bestScore) + " </p>"
                     + "<p> Press R to return to main menu <br>";
QFont font("Consolas", 30, QFont::Bold);

gameOverItem->setHtml(htmlString);
gameOverItem->setFont(font);
gameOverItem->setDefaultTextColor(Qt::blue);
addItem(gameOverItem);

gameOverItem->setPos(QPoint(0,0) -
                      QPoint(gameOverItem->boundingRect().width()/2,
                             gameOverItem->boundingRect().height()/2));

}


void Scene::spawnEnemies() {
Enemy *enemy1 = new Enemy(3);
connect(this, &Scene::gamePause,enemy1, &Enemy::pause);
connect(this, &Scene::gamePlay,enemy1, &Enemy::play);
enemy1->setPos(width() - 200, 100);
addItem(enemy1);
//enemies.append(enemy1);

Enemy *enemy2 = new Enemy(4);
enemy2->setPos(width() - 100, 150);
addItem(enemy2);
connect(this, &Scene::gamePause,enemy2, &Enemy::pause);
connect(this, &Scene::gamePlay,enemy2, &Enemy::play);
//enemies.append(enemy2);
if(option==0){
    connect(enemy1, &Enemy::tankDestroyed, this, &Scene::gameOverGSraphics);
    connect(enemy2, &Enemy::tankDestroyed, this, &Scene::gameOverGSraphics);
}
if(option==1){
    connect(enemy1, &Enemy::tankDestroyed, this, &Scene::tankDestroyed);
    connect(enemy2, &Enemy::tankDestroyed, this, &Scene::tankDestroyed);
}

}

void Scene::updateEnemies() {
for (auto *enemy : enemies) {
    enemy->move();
}
}
void Scene::showMap()
{

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
    emit gamePause();
    pause=true;
}
if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
    hidePauseGraphics();
    emit gamePlay();
    pause=false;
}

QGraphicsScene::keyPressEvent(event);
if(!pause){
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

void Scene::tankDestroyed()
{
    tank_destroyed++;
    qDebug() << tank_destroyed;
    if(tank_destroyed==2){
        gameOverGSraphics();
    }
}
