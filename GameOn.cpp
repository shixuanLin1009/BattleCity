#include "GameOn.h"
#include "ui_GameOn.h"

GameOn::GameOn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameOn), scene(new Scene)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);//利用ut抓View的地址
    ui->graphicsView ->setFixedSize(800,600);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

GameOn::~GameOn()
{
    delete ui;
    delete scene;
}
