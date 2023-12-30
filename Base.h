#ifndef BASE_H
#define BASE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QWidget>

class Base : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Base(QObject *parent = nullptr,QGraphicsPixmapItem *parent_1 = nullptr);
};

#endif // BASE_H
