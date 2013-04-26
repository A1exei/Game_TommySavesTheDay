#include "mainwindow.h"

MainWindow::MainWindow() 
{

    Layout = new QVBoxLayout;
    GameScene = new QGraphicsScene();
    GameScene->setSceneRect(0,0,850,500);
   
    GameView = new QGraphicsView(GameScene);

    ToolBar = new QToolBar();
    Layout->addWidget(ToolBar);
    
    ScoreLabel = new QLabel("Score: ");
    ToolBar->addWidget(ScoreLabel);

    Score = new QLabel("0000");
    Score->setFrameStyle( QFrame::StyledPanel | QFrame::Plain );
    Score->setAlignment( Qt::AlignCenter );
    ToolBar->addWidget(Score);
    ToolBar->addSeparator();

    Health = new QLabel("Health");
    ToolBar->addWidget(Health);

    HealthBar = new QProgressBar();
    HealthBar->setValue(100);
    HealthBar->setTextVisible(false);
    ToolBar->addWidget(HealthBar);
    ToolBar->addSeparator();

    Start = new QPushButton("START");
    ToolBar->addWidget(Start);
    ToolBar->addSeparator();

    Quit = new QPushButton("QUIT");
    ToolBar->addWidget(Quit);
    ToolBar->addSeparator();

    Layout->addWidget(GameView);


    timer  = new QTimer(this);
    timer->setInterval(5);
    setLayout(Layout);

    Background = new Backdrop();
    GameScene->addItem(Background);
    Background->setPos(-13, -19);

    Background2 = new Backdrop();
    GameScene->addItem(Background2);
    Background2->setPos(900, -19);
    moveBackground2 = false;

    tommy  = new Tommy();
    HorsePic = new QPixmap("Images/HORSE.png");
    HorsePic2 = new QPixmap("Images/HORSE_2.png");
    HorseScaled  = HorsePic->scaled( 150, 150, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    HorseScaled2 = HorsePic2->scaled( 150, 150, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    GameScene->addItem(tommy);
    tommy->setPos(400,350);
    
    bear = new Bear();
    BearPic = new QPixmap("Images/BEAR_1.png");
    BearPic2 = new QPixmap("Images/BEAR_2.png");
    BearScaled = BearPic->scaled( 90, 90, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    BearScaled2 = BearPic2->scaled( 90, 90, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    GameScene->addItem(bear);
    bear->setPos(700,400);




    connect(Start, SIGNAL(clicked()), this, SLOT( start() ));
    connect(Quit, SIGNAL(clicked()), this, SLOT( exit() ));
    connect(timer, SIGNAL(timeout()), this, SLOT( imageRotate() ));
    connect(timer, SIGNAL(timeout()), this, SLOT( objectAnimate() ));
    connect(timer, SIGNAL(timeout()), this, SLOT( tommyJump() ));

    setFocus();

}


void MainWindow::start()
{
    timer->start();
    tommy->setPixmap(HorseScaled);
    bear->setPixmap(BearScaled);
    setFocus();


}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    setFocus();
    switch(event->key())
    {
        case Qt::Key_Space:
            {
                tommyJump();
                tommy->isJumping = true;
            }
            break;

        default:
            QWidget::keyPressEvent(event);

    }

}


void MainWindow::objectAnimate()
{
        int Bx = bear->x();
        if (Bx > -120)
        bear->moveBy(-1, 0);
        if (Bx == -119)
        {
            bear->setPos(900,400);
        }



        int BackX = Background->x();
        int Back2X = Background2->x();
        //cout<<BackX<<endl;
        Background->moveBy(-1,0);
        if (moveBackground2)
        {
            Background2->moveBy(-1,0);
        }
        if (BackX == -298)
        {
            Background2->setPos(1200, -19);
            moveBackground2 = true;

        }
        if (Back2X == -298)
        {
            Background->setPos(1200, -19);

        }

}


void MainWindow::imageRotate()
{

    if (tommy->GIFcounter%35 == 0)
    {
        if (tommy->moving == true)
        {
             tommy->setPixmap(HorseScaled);
             tommy->moving = false;
             tommy->GIFcounter = 0;
        }
        else
        {
            tommy->setPixmap(HorseScaled2);
            tommy->moving = true;
            tommy->GIFcounter = 0;
        }


    }
    tommy->GIFcounter++;

    /////////////////////////////////////////////////////////
    if (bear->GIFcounter%40 == 0)
    {
        if (bear->moving == true)
        {
             bear->setPixmap(BearScaled);
             bear->moving = false;
             bear->GIFcounter = 0;
        }
        else
        {
            bear->setPixmap(BearScaled2);
            bear->moving = true;
            bear->GIFcounter = 0;
        }


    }
    bear->GIFcounter++;
    

    ///////////////////////////////////////////////////////
    
    
}

void MainWindow::tommyJump()
{
        int Tx = tommy->x();

        if(tommy->isJumping)
        {
            tommy->moveBy(.1,-1);
            tommy->jumpCounter++;

            if (tommy->jumpCounter == 150)
            {
                tommy->isJumping = false;
                tommy->isFalling = true;
            }
        }

        if (tommy->isFalling)
        {
            tommy->moveBy(.1,1);
            tommy->jumpCounter++;

            if (tommy->jumpCounter == 300)
            {
                tommy->isJumping = false;
                tommy->isFalling = false;
            }
        }

        if ( (tommy->isJumping == false) && (tommy->isFalling == false) && (Tx != 400))
        {
            tommy->jumpCounter = 0;
            tommy->moveBy(-.75,0);
        }
}

void MainWindow::exit()
{
    close();
    qApp->quit();
}

MainWindow::~MainWindow()
{

}
