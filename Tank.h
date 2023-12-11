#ifndef TANK_H
#define TANK_H

#include <QObject>
#include <QWidget>
#include<QGraphicsRectItem>

class Tank:public QGraphicsRectItem
{
public:
    Tank(QGraphicsRectItem *parent=nullptr);
};

#endif // TANK_H
