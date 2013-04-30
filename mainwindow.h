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
#include <QString>
#include <QProgressBar>
#include <QListView>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <boost/lexical_cast.hpp>
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

/** Main class that facilitates gameplay, coordinates object addittion/movement, keeps track of score, and start
    and ends game */
class MainWindow : public QWidget
{
    Q_OBJECT
    
public:
    /** Constructor, allocates main game items */
    MainWindow();

    /** Destructor */
    ~MainWindow();

    /** stores timer interval, used to increase game speed later on */
    int timeInterval;

    /** Keeps track of time to coordinate timeInterval management */
    int timeCounter;
   
private:
    //////////////////           Game Pictures + Objects   ////////////////////////
    QGraphicsPixmapItem* StartView;
    QPixmap* StartPic;
    QPixmap StartPicScaled;
    QTextEdit* NameBox;
    QString nameString;
    QGraphicsPixmapItem* EndView;
    QPixmap* EndPic;
    QPixmap EndPicScaled;
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

    //////////////////////////        Scrolling Background         /////////////////////////
    Backdrop* Background;
    Backdrop* Background2;
    bool moveBackground2;

    //////////////////////////     Main Character Oject       /////////////////////////
    Tommy* tommy;
    QPixmap* HorsePic;
    QPixmap* HorsePic2;
    QPixmap HorseScaled;
    QPixmap HorseScaled2;
    QPixmap blank;
    bool tommyJumping;
    bool leftPosition;
    

    //////////////////////////        Bear Object         /////////////////////////
    Bear* bear;
    QPixmap* BearPic;
    QPixmap* BearPic2;
    QPixmap BearScaled;
    QPixmap BearScaled2;
    bool bearExists;


    //////////////////////////        DPS Object         /////////////////////////
    DPS* dps;
    QPixmap* DPSpic1;
    QPixmap* DPSpic2;
    QPixmap DPSscaled1;
    QPixmap DPSscaled2;
    bool DPSexists;


    //////////////////////////        Tree Object         /////////////////////////
    Tree* tree;
    QPixmap* TreePic1;
    QPixmap* TreePic2;
    QPixmap TreeScaled1;
    QPixmap TreeScaled2;
    int treeJumpCounter;
    bool treeIsJumping;
    bool treeIsFalling;
    bool treeExists;


    //////////////////////////        Devil Object         /////////////////////////
    Devil* devil;
    QPixmap* DevilPic;
    QPixmap* DevilPic2;
    QPixmap DevilScaled;
    QPixmap DevilScaled2;
    bool shootFireball;
    bool devilExists;


    //////////////////////////        Fireball Object         /////////////////////////
    Fireball* fireball;
    QPixmap* FireballPic;
    QPixmap* FireballPic2;
    QPixmap FireballScaled;
    QPixmap FireballScaled2;
    bool fireballExists;


    //////////////////////////        Duck Object         /////////////////////////
    Duck* duck;
    QPixmap* DuckPic;
    QPixmap DuckScaled;
    int DUCK_Y;
    bool duckExists;
    bool dropBook;

    //////////////////////////       Projectile Object         /////////////////////////
    Book* book;
    QPixmap* BookPic;
    QPixmap* BookPic2;
    QPixmap BookScaled;
    QPixmap BookScaled2;
    bool bookExists;

    //////////////////////////        Game Object Properties         /////////////////////////
    vector<GameObject*> GameObjects;
    int BearCounter;
    int bearStartX;
    double bearVelocty;
    int numBears;
    int MAX_BEARS;
    int DPScounter;
    int DPSlimit;
    int treeCounter;
    int treeStartX;
    double treeVelocity;
    int devilCounter;
    int duckCounter;

    ////////////////      Help With Game Speed and Score Increase //////////////////
    double scoreFactor;
    int timeDifference;
    clock_t tStart, tCurrent;

protected:
    /** Reads key presses from the keyboard */
    void keyPressEvent(QKeyEvent *event);

private slots:
    /** Starts game */
    void start();

    /** Pauses game */
    void pause();

    /** Ends game */
    void exit();

    /** Simulates object movement */
    void objectAnimate();

    /** Simulates shotting of fireballs */
    void fireballShoot();

    /** Simulates flying of projectile */
    void bookDrop();

    /** Simulates object animation */
    void imageRotate();

    /** Regulates keyPress inputs */
    void jumpRegulator();

    /** Makes main character jump */
    void tommyJump();

    /** Checks to see if main character is contact with any other game object */
    void tommyCollision();

    /** Adds items to the game at various intervals */
    void addItems();

    /** Keeps track of score */
    void scoreCounter();

    /** Keeps track of game speed*/
    void speedUpdater();

};

#endif // MAINWINDOW_H
