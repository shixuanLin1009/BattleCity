#include "Scene.h"

Scene::Scene(QGraphicsScene *parent) : QGraphicsScene(parent)
{
    // 初始化 tank，這裡假設 Tank 類別已經存在
    tank = new Tank();  // 記得在 Scene 的析構函式中刪除 tank，以避免記憶體洩漏

    // 初始化坦克的圓點
    tankMarker = new QGraphicsEllipseItem(-5, -5, 10, 10);  // 以坦克為中心的半徑 5 的圓
    tankMarker->setPen(Qt::NoPen);
    tankMarker->setBrush(Qt::red);  // 使用紅色填充
    tankMarker->setPos(tank->x(), tank->y());  // 將圓點設置在坦克的位置
    addItem(tankMarker);

    // 將 tank 和坦克的圓點添加到場景中
    addItem(tank);
}

void Scene::displayTextOnScene(const QString &text)
{
    // 使用 addText 方法在畫面上添加文字
    QGraphicsTextItem *textItem = addText(text);

    // 設定文字的位置，這裡設定為畫面中央
    int xPos = width() / 2 - textItem->boundingRect().width() / 2;
    int yPos = height() / 2 - textItem->boundingRect().height() / 2;
    textItem->setPos(xPos, yPos);
}
