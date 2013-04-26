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


    tommy  = new Tommy();
    bear = new Bear();

    GameScene->addItem(bear);
    GameScene->addItem(tommy);

    tommy->setPos(400,350);
    bear->setPos(700,400);

    timer  = new QTimer(this);
    timer->setInterval(10);


    setFocus();
    setLayout(Layout);

    HorsePic = new QPixmap("Images/HORSE.png");
    HorsePic2 = new QPixmap("Images/HORSE_2.png");
    HorseScaled  = HorsePic->scaled( 150, 150, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    HorseScaled2 = HorsePic2->scaled( 150, 150, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    
    BearPic = new QPixmap("Images/BEAR_1.png");
    BearPic2 = new QPixmap("Images/BEAR_2.png");
    BearScaled = BearPic->scaled( 100, 100, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    BearScaled2 = BearPic2->scaled( 100, 100, Qt::IgnoreAspectRatio, Qt::FastTransformation );


    connect(Start, SIGNAL(clicked()), this, SLOT( start() ));
    connect(Quit, SIGNAL(clicked()), this, SLOT( exit() ));
    connect(timer, SIGNAL(timeout()), this, SLOT( imageRotate() ));
    connect(timer, SIGNAL(timeout()), this, SLOT( objectAnimate() ));
}


void MainWindow::start()
{

    timer->start();
    tommy->setPixmap(HorseScaled);
    bear->setPixmap(BearScaled);

}


void MainWindow::keyPressEvent(QKeyEvent *event)
{

    switch(event->key())
    {
        case Qt::Key_Space:
            {
               cout<<"Test"<<endl;
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

}


void MainWindow::imageRotate()
{

    if (tommy->GIFcounter%30 == 0)
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
    if (bear->GIFcounter%35 == 0)
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


}

void MainWindow::exit()
{
    close();
    qApp->quit();
}

MainWindow::~MainWindow()
{

}
