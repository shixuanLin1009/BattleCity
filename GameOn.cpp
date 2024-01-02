#include "GameOn.h"
#include <QKeyEvent>
#include "ui_GameOn.h"
#include "widget.h"
#include <QGraphicsSceneMouseEvent>

GameOn::GameOn(int option, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameOn), scene(new Scene(option))
{
    // Set background color of the scene
    scene->setBackgroundBrush(QBrush(QColor("#D9D9D9")));

    ui->setupUi(this);
    ui->graphicsView->setScene(scene);//利用ut抓View的地址
    ui->graphicsView ->setFixedSize(800,600);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene->addLine(-400,0,400,0,QPen(Qt::blue));
    scene->addLine(0,-300,0,300,QPen(Qt::red));

}

GameOn::~GameOn()
{
    delete ui;
    delete scene;
}

void GameOn::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_R) {
        this->hide();
        Widget* b = new Widget();
        b->show();
    }
    QGraphicsScene::keyPressEvent(event);
}
