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
#include <cstdlib>
using namespace std;

class MainWindow;

class GameObject : public QWidget
{

public slots:
   virtual void movement() = 0;
};



#endif // GAMEOBJECT_H
