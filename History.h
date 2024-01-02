#ifndef HISTORY_H
#define HISTORY_H

#include "qlistwidget.h"
#include<QGraphicsScene>
#include <QWidget>
#include<Scene.h>

namespace Ui {
class History;
}
QT_END_NAMESPACE
class History : public QWidget, QGraphicsScene
{
public:
    explicit History(QWidget *parent = nullptr);
    ~History();

private:
    Ui::History *ui;
    Scene *scene;
protected:
    void keyPressEvent(QKeyEvent *event);
    void readTextFileAndPopulateListWidget(const QString &filePath);
};

#endif // HISTORY_H

