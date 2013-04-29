#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QtGui/QApplication>
#include <QWidget>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <QApplication>
#include <QtAlgorithms>
#include <QListWidgetItem>
#include <QtGui>
#include <QtCore>
#include <QFont>
#include <QLabel>
#include <QListView>
#include <QGraphicsPixmapItem>
#include <cstdlib>
using namespace std;



class GameObject : public QGraphicsPixmapItem
{
        public:
           virtual int ObjectType() = 0;
           bool moving;
           int GIFcounter;
};



#endif // GAMEOBJECT_H
