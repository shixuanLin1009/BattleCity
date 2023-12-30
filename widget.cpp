#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    ,ui(new Ui::Widget)
{
    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_player1_clicked()
{
    this->hide();
    GameOn* b = new GameOn(0);
    b->show();
}

void Widget::on_player2_clicked()
{
    this->hide();
    GameOn* b2 = new GameOn(1);
    b2->show();


}
