#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include "Tank.h"

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QGraphicsScene *parent = nullptr);
    Tank *tank;

public slots:
    void displayTextOnScene(const QString &text);

private:
    QGraphicsEllipseItem *tankMarker;  // 圓點表示坦克的位置

signals:

};

#endif // SCENE_H
