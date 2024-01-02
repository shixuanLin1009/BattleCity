#include "History.h"
#include "ui_History.h"
#include <QKeyEvent>
#include "widget.h"
#include <QGraphicsSceneMouseEvent>
#include <QFile>

History::History(QWidget *parent) :
    QWidget(parent), ui(new Ui::History)
{
    ui->setupUi(this);

    ui->listWidget->addItem("History");
    // Open the file
    readTextFileAndPopulateListWidget(":/text/History.txt");

}

History::~History()
{
    delete ui;
}

void History::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape) {
        this->hide();
        Widget* b = new Widget();
        b->show();
    }
    QGraphicsScene::keyPressEvent(event);
}

void History::readTextFileAndPopulateListWidget(const QString &filePath)
{
    // Open the file
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Could not open file: " << file.errorString();
        return;
    }

    // Read the contents of the file
    QTextStream in(&file);
    while (!in.atEnd())
    {
        // Read each line
        QString line = in.readLine();

        // Create a QListWidgetItem and add it to the listWidget
        QListWidgetItem *item = new QListWidgetItem(line);
        ui->listWidget->addItem(item);
    }

    // Close the file
    file.close();
}
