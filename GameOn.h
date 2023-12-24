#ifndef GAMEON_H
#define GAMEON_H

#include <QWidget>
#include<Scene.h>
namespace Ui { class GameOn; }
QT_END_NAMESPACE

class GameOn : public QWidget
{
    Q_OBJECT

public:
    explicit GameOn(QWidget *parent = nullptr);
    ~GameOn();

private slots:

private:
    Ui::GameOn *ui;
    Scene *scene;
};

#endif // GAMEON_H
