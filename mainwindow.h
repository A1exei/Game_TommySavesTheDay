#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
#include <iostream>
#include <vector>
#include <cstdlib>
#include "Tommy.h"
#include "Bear.h"

using namespace std;


class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void show();
   QToolBar* ToolBar;
   QVBoxLayout* Layout;
   QLabel* ScoreLabel;
   QLabel* Score;
   QLabel* Health;
   Tommy* tommy;
   Bear* bear;
   QTimer* timer;


private:
    QGraphicsScene *scene;
    QGraphicsScene *GameScene;
    QGraphicsView *MainView;
    QGraphicsView *GameView;

private slots:
    void exit();
    void objectAnimate();

};

#endif // MAINWINDOW_H
