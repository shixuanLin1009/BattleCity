#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<Scene.h>
#include<GameOn.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    GameOn *gameon;
private slots:
    void on_player1_clicked();
    void on_player2_clicked();

private:
    Ui::Widget *ui;
    Scene *scene;

};
#endif // WIDGET_H
