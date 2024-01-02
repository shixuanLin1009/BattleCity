#include "Scene.h"
#include "Enemy.h"
#include "Obstacle.h"
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QFile>
#include<QRandomGenerator>

Scene::Scene(int opt, QGraphicsScene *parent)
    : QGraphicsScene{parent},tank(new Tank)
{
    tank_destroyed=0;
    option=opt;
    pause=false;
    if(opt==2){
        QFile file(":/text/Restart.txt");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&file);
        QString line1 = in.readLine();
        QString line2 = in.readLine();
        QString line3 = in.readLine();

        // Close the file
        file.close();
        totalEnemy = line1.toInt();
        score=line2.toInt();
        bestScore=line3.toInt();
        int spawn=totalEnemy/2;
        for(int i=0; i<spawn;i++){
            spawnEnemies();
        }
    }

    if(opt==0||opt==1){
        score=0;
        bestScore=0;
        totalEnemy=1;
        spawnEnemies();
    }
    addItem(tank);
    moveTimer = new QTimer();
    connect(moveTimer, &QTimer::timeout, this, &Scene::updateEnemies);

    moveTimer->start(200); // Update every 200 milliseconds

    tank->setPos(0,220);

    if(opt==1){

        tank2 = new Tank();
        addItem(tank2);
        tank2->setPos(-40,220);
    }
    showMap();

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

void Scene::gameOverGraphics()
{    


gameOverItem = new QGraphicsTextItem();
QString htmlString =   "<p> Game Over <br>"
                     "<p> Score : " + QString::number(score) + " <br>"
                     + " Best Score Today: " + QString::number(bestScore) + " </p>"
                     + "<p> Press R to return to main menu <br>";
QFont font("Consolas", 30, QFont::Bold);

gameOverItem->setHtml(htmlString);
gameOverItem->setFont(font);
gameOverItem->setDefaultTextColor(Qt::blue);
addItem(gameOverItem);

gameOverItem->setPos(QPoint(0,0) -
                      QPoint(gameOverItem->boundingRect().width()/2,
                             gameOverItem->boundingRect().height()/2));

saveScoresToFile("C:/Users/ASUS/Documents/GitHub/BattleCity/History.txt");
updateStats("C:/Users/ASUS/Documents/GitHub/BattleCity/Restart.txt");
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

void Scene::showIce()
{
    for(int i=0;i<=7;i++)
    {
        Ice *j =new Ice();
        j->setPos(-160+40*i,140);
        addItem(j);
        j++;
    }
}

void Scene::showWater()
{
    for(int i=0;i<=7;i++)
    {
        Water *j =new Water();
        j->setPos(-160+40*i,-60);
        addItem(j);
        j++;
    }
}


void Scene::spawnEnemies() {

    int ran= QRandomGenerator::global()->bounded(0, 5);
    int ran_2= QRandomGenerator::global()->bounded(0, 5);

    totalEnemy++;

    Enemy *enemy1 = new Enemy(ran);
    enemy1->setPos(-240, -260);
    addItem(enemy1);
    connect(this, &Scene::gamePause,enemy1, &Enemy::pause);
    connect(this, &Scene::gamePlay,enemy1, &Enemy::play);
    Enemy *enemy2 = new Enemy(ran_2);
    enemy2->setPos(240, -220);
    addItem(enemy2);


connect(this, &Scene::gamePause,enemy1, &Enemy::pause);
connect(this, &Scene::gamePlay,enemy1, &Enemy::play);
connect(this, &Scene::gamePause,enemy2, &Enemy::pause);
connect(this, &Scene::gamePlay,enemy2, &Enemy::play);
//
if(option==0){
    connect(enemy1, &Enemy::tankDestroyed, this, &Scene::gameOverGraphics);
    connect(enemy2, &Enemy::tankDestroyed, this, &Scene::gameOverGraphics);
}
if(option==1){
    connect(enemy1, &Enemy::tankDestroyed, this, &Scene::tankDestroyed);
    connect(enemy2, &Enemy::tankDestroyed, this, &Scene::tankDestroyed);
}

void Scene::updateEnemies() {
for (auto *enemy : enemies) {
    enemy->move();
}
}
void Scene::showMap()
{
    showBase();
    // Trees
    showIce();
    showWater();

    for(int i=0;i<=240;i+=40){

        Tree *a = new Tree();
        a->setPos(-400+i,-60);
        addItem(a);
        a++;

    }

    for(int i=0;i<=760;i+=40){
        //底部邊界
        Obstacle *j = new Obstacle();
        j->setPos(-400+i,260);
        addItem(j);
        j++;
        //頂部邊界
        Obstacle *k = new Obstacle();
        k->setPos(-400+i,-300);
        addItem(k);
        k++;

    }

    for(int i=0;i<=560;i+=40){
        //左側邊界
        Obstacle *j = new Obstacle();
        j->setPos(-400,-300+i);
        addItem(j);
        j++;
        //右側邊界
        Obstacle *k = new Obstacle();
        k->setPos(360,-300+i);
        addItem(k);
        k++;

    }

    // 內部障礙物
    for(int i=0;i<=680;i+=120){

        Water *j = new Water();
        j->setPos(-320+i,-220);
        addItem(j);
        j++;
        Stone *k = new Stone();
        k->setPos(-320+i,-180);
        addItem(k);
        k++;
        Stone *l = new Stone();
        l->setPos(-320+i,-140);
        addItem(l);
        l++;
        Stone *m = new Stone();
        m->setPos(-320+i,-100);
        addItem(m);
        m++;
    }

    // 內部障礙物
    for(int i=0;i<=120;i+=120){

        Stone *j = new Stone();
        j->setPos(-320+i,60);
        addItem(j);
        j++;
        Stone *k = new Stone();
        k->setPos(-320+i,100);
        addItem(k);
        k++;
        Stone *l = new Stone();
        l->setPos(-320+i,140);
        addItem(l);
        l++;
        Stone *m = new Stone();
        m->setPos(-320+i,180);
        addItem(m);
        m++;
    }

    for(int i=0;i<=120;i+=120){

        Stone *j = new Stone();
        j->setPos(160+i,60);
        addItem(j);
        j++;
        Stone *k = new Stone();
        k->setPos(160+i,100);
        addItem(k);
        k++;
        Stone *l = new Stone();
        l->setPos(160+i,140);
        addItem(l);
        l++;
        Stone *m = new Stone();
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

    int step = tank->getSpeed();

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
        connect(bullet,&Bullet::bulletHitsBase,this,&Scene::gameOverGraphics);
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
            connect(bullet2,&Bullet::bulletHitsBase,this,&Scene::gameOverGraphics);
            bullet2->setPos(pos2);
            addItem(bullet2);
        }
    }
}
QGraphicsScene::keyPressEvent(event);
}

void Scene::incrementScore()
{
score+=100;
spawnEnemies();
if (score > bestScore) {
    bestScore = score;
    }
}

void Scene::tankDestroyed()
{
    tank_destroyed++;
    qDebug() << tank_destroyed;
    if (tank_destroyed == 2) {
    tank->takeDamage(1);
    tank2->takeDamage(1);
    gameOverGraphics();
    }
}

void Scene::saveScoresToFile(const QString &filePath)
{
    // Open the file for appending
    QFile file(filePath);
    if (!file.open(QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "Could not open file for appending: " << file.errorString();
        return;
    }

    // Write scores to the file
    QTextStream out(&file);
    out << score << "\n";

    // Check for errors during writing
    if (out.status() != QTextStream::Ok)
    {
        qDebug() << "Error writing to file: " << file.errorString();
    }

    // Close the file
    file.close();
}
void Scene::updateStats(const QString &filePath)
{
    // Open the file for writing (rewriting)
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Could not open file for writing: " << file.errorString();
        return;
    }

    // Write scores to the file
    QTextStream out(&file);
    out << totalEnemy << "\n";
    out << score << "\n";
    out << bestScore << "\n";

    // Check for errors during writing
    if (out.status() != QTextStream::Ok)
    {
        qDebug() << "Error writing to file: " << file.errorString();
    }

    // Close the file
    file.close();
}
