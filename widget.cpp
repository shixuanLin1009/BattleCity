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

void Widget::on_history_clicked()
{
    this->hide();
    History* h = new History();
    h->show();
}

void Widget::on_restart_clicked()
{
    this->hide();
    GameOn* b2 = new GameOn(2);
    b2->show();
}
void Widget::on_quit_clicked()
{
    this->close();
}
