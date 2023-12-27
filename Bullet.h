#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QWidget>
#include<QGraphicsRectItem>
#include<QTimer>

class Bullet : public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit Bullet(QObject *parent = nullptr,QGraphicsRectItem *parent_1 = nullptr);
    ~Bullet();
public slots:
    void shot();
private:
    QTimer *timer;

};

#endif // BULLET_H
