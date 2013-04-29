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
#include <stdlib.h>
#include <stdio.h>
#include "GameObject.h"
#include "Tommy.h"
#include "Bear.h"
#include "Backdrop.h"
#include "DPS.h"
#include "Tree.h"
#include "Devil.h"
#include "Fireball.h"
#include "Duck.h"
#include "Book.h"

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
    QPushButton* Pause;
    QPushButton* Quit;
    QTimer* timer;

    Backdrop* Background;
    Backdrop* Background2;
    bool moveBackground2;

    Tommy* tommy;
    QPixmap* HorsePic;
    QPixmap* HorsePic2;
    QPixmap HorseScaled;
    QPixmap HorseScaled2;
    QPixmap blank;
    bool tommyJumping;
    bool leftPosition;
    
    Bear* bear;
    QPixmap* BearPic;
    QPixmap* BearPic2;
    QPixmap BearScaled;
    QPixmap BearScaled2;
    bool bearExists;

    DPS* dps;
    QPixmap* DPSpic1;
    QPixmap* DPSpic2;
    QPixmap DPSscaled1;
    QPixmap DPSscaled2;
    bool DPSexists;

    Tree* tree;
    QPixmap* TreePic1;
    QPixmap* TreePic2;
    QPixmap TreeScaled1;
    QPixmap TreeScaled2;
    int treeJumpCounter;
    bool treeIsJumping;
    bool treeIsFalling;
    bool treeExists;

    Devil* devil;
    QPixmap* DevilPic;
    QPixmap* DevilPic2;
    QPixmap DevilScaled;
    QPixmap DevilScaled2;
    bool shootFireball;
    bool devilExists;

    Fireball* fireball;
    QPixmap* FireballPic;
    QPixmap* FireballPic2;
    QPixmap FireballScaled;
    QPixmap FireballScaled2;
    bool fireballExists;

    Duck* duck;
    QPixmap* DuckPic;
    QPixmap DuckScaled;
    int DUCK_Y;
    bool duckExists;
    bool dropBook;

    Book* book;
    QPixmap* BookPic;
    QPixmap* BookPic2;
    QPixmap BookScaled;
    QPixmap BookScaled2;
    bool bookExists;


    vector<GameObject*> GameObjects;
    int BearCounter;
    int bearStartX;
    int numBears;
    int MAX_BEARS;

    int DPScounter;
    int DPSlimit;

    int treeCounter;
    int treeStartX;

    int devilCounter;

    int duckCounter;




protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void start();
    void pause();
    void exit();
    void objectAnimate();
    void fireballShoot();
    void bookDrop();
    void imageRotate();
    void jumpRegulator();
    void tommyJump();
    void tommyCollision();
    void addItems();

};

#endif // MAINWINDOW_H
