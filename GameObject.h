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


/** GameObject superclass that holds core object functions */
class GameObject : public QGraphicsPixmapItem
{
        public:
           /** Returns derived object type, helps to differentiate between different inherited
             classes
                @return int representing object type*/
           virtual int ObjectType() = 0;

           /** bool value used to facilitate simulated object animation **/
           bool moving;

           /** int value used to facilitate simulated object animation **/
           int GIFcounter;
};



#endif // GAMEOBJECT_H
