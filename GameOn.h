#ifndef GAMEON_H
#define GAMEON_H
#include<QGraphicsScene>
#include <QWidget>
#include<Scene.h>

namespace Ui { class GameOn; }
QT_END_NAMESPACE

class GameOn : public QWidget, QGraphicsScene
{

public:
    explicit GameOn(QWidget *parent = nullptr);
    ~GameOn();

private slots:

private:
    Ui::GameOn *ui;
    Scene *scene;
protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // GAMEON_H
