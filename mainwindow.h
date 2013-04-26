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
#include <QProgressBar>
#include <QListView>
#include <iostream>
#include <vector>
#include <cstdlib>
#include "GameObject.h"
#include "Tommy.h"
#include "Bear.h"

using namespace std;


class MainWindow : public QWidget
{
    Q_OBJECT
    
public:
    MainWindow();
    ~MainWindow();
   
private:
    QToolBar* ToolBar;
    QGraphicsScene *GameScene;
    QGraphicsView *GameView;
    QVBoxLayout* Layout;
    QLabel* ScoreLabel;
    QLabel* Score;
    QLabel* Health;
    QProgressBar* HealthBar;
    QPushButton* Start;
    QPushButton* Quit;
    QTimer* timer;

    Tommy* tommy;
    QPixmap* HorsePic;
    QPixmap* HorsePic2;
    QPixmap HorseScaled;
    QPixmap HorseScaled2;
    
    Bear* bear;
    QPixmap* BearPic;
    QPixmap* BearPic2;
    QPixmap BearScaled;
    QPixmap BearScaled2;

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void start();
    void exit();
    void objectAnimate();
    void imageRotate();
    void tommyJump();

};

#endif // MAINWINDOW_H
