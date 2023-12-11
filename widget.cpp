#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    ,scene(new Scene), ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);//利用ut抓View的地址
    ui->graphicsView ->setFixedSize(800,600);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}

Widget::~Widget()
{
    delete ui;
}

