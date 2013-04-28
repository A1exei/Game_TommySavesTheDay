#include "mainwindow.h"

MainWindow::MainWindow() 
{

    Layout = new QVBoxLayout;
    GameScene = new QGraphicsScene();
    GameScene->setSceneRect(0,0,850,500);
   
    GameView = new QGraphicsView(GameScene);

    ToolBar = new QToolBar();

    
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

    Pause = new QPushButton("PAUSE");
    ToolBar->addWidget(Pause);
    ToolBar->addSeparator();

    Quit = new QPushButton("QUIT");
    ToolBar->addWidget(Quit);
    ToolBar->addSeparator();

    Layout->addWidget(GameView);
    Layout->addWidget(ToolBar);


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
    HorsePic = new QPixmap("Images/HORSE_1.png");
    HorsePic2 = new QPixmap("Images/HORSE_2.png");
    HorseScaled  = HorsePic->scaled( 150, 150, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    HorseScaled2 = HorsePic2->scaled( 150, 150, Qt::IgnoreAspectRatio, Qt::FastTransformation );

    GameScene->addItem(tommy);
    tommy->setPos(400,350);
    
    bear = new Bear();
    BearPic = new QPixmap("Images/BEAR_1.png");
    BearPic2 = new QPixmap("Images/BEAR_2.png");
    BearScaled = BearPic->scaled( 80, 80, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    BearScaled2 = BearPic2->scaled( 80, 80, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    GameScene->addItem(bear);
    bear->setPos(700,410);

    dps = new DPS();
    DPSpic1 = new QPixmap("Images/DPS_1.png");
    DPSpic2 = new QPixmap("Images/DPS_3.png");
    DPSscaled1 = DPSpic1->scaled( 90, 150, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    DPSscaled2 = DPSpic2->scaled( 90, 150, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    GameScene->addItem(dps);
    dps->setPos(-200,400);

    tree = new Tree();
    TreePic1 = new QPixmap("Images/TREE_1.png");
    TreePic2 = new QPixmap("Images/TREE_2.png");
    TreeScaled1 = TreePic1->scaled( 80, 70, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    TreeScaled2 = TreePic2->scaled( 80, 70, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    GameScene->addItem(tree);
    tree->setPos(900,410);
    tree->isJumping = true;

    devil = new Devil();
    DevilPic = new QPixmap("Images/DEVIL_1.png");
    DevilPic2 = new QPixmap("Images/DEVIL_2.png");
    DevilScaled = DevilPic->scaled( 90, 90, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    DevilScaled2 = DevilPic2->scaled( 90, 90, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    GameScene->addItem(devil);
    devil->setPos(1200,410);

    fireball = new Fireball();
    FireballPic = new QPixmap("Images/FIREBALL_1.png");
    FireballPic2 = new QPixmap("Images/FIREBALL_2.png");
    FireballScaled = FireballPic->scaled( 45, 45, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    FireballScaled2 = FireballPic2->scaled( 45, 45, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    GameScene->addItem(fireball);
    fireball->setPos(600, 400);

    duck = new Duck();
    DuckPic = new QPixmap("Images/DUCK.png");
    DuckScaled = DuckPic->scaled( 100, 90, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    GameScene->addItem(duck);
    DUCK_Y = 100;
    duck->setPos(1500, DUCK_Y);

    book = new Book();
    BookPic = new QPixmap("Images/POOP_1.png");
    BookScaled = BookPic->scaled( 40, 40, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    BookPic2 = new QPixmap("Images/POOP_2.png");
    BookScaled2 = BookPic2->scaled( 40, 40, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    GameScene->addItem(book);
    book->setPos(200, DUCK_Y);


    connect(Start, SIGNAL(clicked()), this, SLOT( start() ));
    connect(Quit, SIGNAL(clicked()), this, SLOT( exit() ));
    connect(Pause, SIGNAL(clicked()), this, SLOT( pause() ));
    connect(timer, SIGNAL(timeout()), this, SLOT( imageRotate() ));
    connect(timer, SIGNAL(timeout()), this, SLOT( objectAnimate() ));
    connect(timer, SIGNAL(timeout()), this, SLOT( jumpRegulator() ));
    connect(timer, SIGNAL(timeout()), this, SLOT( tommyJump() ));
    connect(timer, SIGNAL(timeout()), this, SLOT( fireballShoot() ));
    connect(timer, SIGNAL(timeout()), this, SLOT( bookDrop() ));

    setFocus();

}


void MainWindow::start()
{
    timer->start();
    tommy->setPixmap(HorseScaled);
    bear->setPixmap(BearScaled);
    dps->setPixmap(DPSscaled1);
    devil->setPixmap(DevilScaled);
    duck->setPixmap(DuckScaled);
    setFocus();


}


void MainWindow::keyPressEvent(QKeyEvent *event)
{

    switch(event->key())
    {
        case Qt::Key_Space:
            {
                if (tommy->jumpCounter == -1 || tommy->jumpCounter == 0)
                {
                     tommy->isJumping = true;
                }
            }
            break;

       case Qt::Key_Left:
        {

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
        bear->moveBy(-1.5, 0);
        if (Bx == -120)
        {
            bear->setPos(900,410);
        }
//////////////////////////////////////////////////////

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

///////////////////////////////////////////////////

        int DPSx = dps->x();
        if (DPSx < 40)
        dps->moveBy(.25, 0);

//////////////////////////////////////////////////

        int TreeX = tree->x();
        int TreeY = tree->y();
        //cout<<TreeX<<endl;
        if(tree->isJumping)
            {
                tree->moveBy(-2,-2);
                tree->jumpCounter++;

                if (tree->jumpCounter == 200)
                {
                    tree->isJumping = false;
                    tree->isFalling = true;
                }
            }

            if (tree->isFalling)
            {
                tree->moveBy(-2,2);
                tree->jumpCounter++;

                if (tree->jumpCounter == 400)
                {
                    tree->isJumping = false;
                    tree->isFalling = false;
                }
            }

            if ((tree->isJumping == false) && (tree->isFalling == false) )
            {
                tree->isJumping = true;
                tree->jumpCounter = 0;
            }

            if (TreeX < -120 && TreeY == 410)
            {
                tree->setPos(1000, 410);
            }
///////////////////////////////////////////////////////////
            if (devil->scene() == GameScene)
            {
                int Dx = devil->x();
                if (Dx > 650)
                    devil->moveBy(-1, 0);
                if (Dx == 650)
                {
                    devil->shootFireball = true;
                    fireball->setPixmap(FireballScaled);
                    GameScene->removeItem(devil);
                }
            }
//////////////////////////////////////////////////////////////
            int DuckX = duck->x();

            if (DuckX > -500)
                duck->moveBy(-2, 0);

            if (DuckX == 200)
            {
                duck->dropBook = true;
                book->setPixmap(BookScaled);
            }

            if (DuckX == -500)
            {
                duck->setPos(1500,DUCK_Y);
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
    if (bear->GIFcounter%42 == 0)
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
    if (dps->GIFcounter%40 == 0)
    {
        if (dps->moving == true)
        {
             dps->setPixmap(DPSscaled1);
             dps->moving = false;
             dps->GIFcounter = 0;
        }
        else
        {
            dps->setPixmap(DPSscaled2);
            dps->moving = true;
            dps->GIFcounter = 0;
        }
    }
    dps->GIFcounter++;
   ///////////////////////////////////////////////////////
   if (tree->GIFcounter%50 == 0)
    {
        if (tree->moving == true)
        {
             tree->setPixmap(TreeScaled1);
             tree->moving = false;
             tree->GIFcounter = 0;
        }
        else
        {
            tree->setPixmap(TreeScaled2);
            tree->moving = true;
            tree->GIFcounter = 0;
        }
    }
    tree->GIFcounter++;
//////////////////////////////////////////////////////
    if (devil->GIFcounter%42 == 0)
    {
        if (devil->moving == true)
        {
             devil->setPixmap(DevilScaled);
             devil->moving = false;
             devil->GIFcounter = 0;
        }
        else
        {
            devil->setPixmap(DevilScaled2);
            devil->moving = true;
            devil->GIFcounter = 0;
        }
    }
    devil->GIFcounter++;

//////////////////////////////////////////////////////

    if (devil->shootFireball == true)
    {
        if (fireball->GIFcounter%30 == 0)
            {
                if (fireball->moving == true)
                {
                     fireball->setPixmap(FireballScaled);
                     fireball->moving = false;
                     fireball->GIFcounter = 0;
                }
                else
                {
                    fireball->setPixmap(FireballScaled2);
                    fireball->moving = true;
                    fireball->GIFcounter = 0;
                }
            }
       fireball->GIFcounter++;
    }
    else if ((devil->shootFireball == false) && (fireball->scene() == GameScene) && (fireball->x() == 100))
    {
        GameScene->removeItem(fireball);
    }
////////////////////////////////////////////////////////////////

    if (duck->dropBook == true)
    {
        if (book->GIFcounter%30 == 0)
            {
                if (book->moving == true)
                {
                     book->setPixmap(BookScaled);
                     book->moving = false;
                     book->GIFcounter = 0;
                }
                else
                {
                    book->setPixmap(BookScaled2);
                    book->moving = true;
                    book->GIFcounter = 0;
                }
            }
       book->GIFcounter++;
    }
    else if ((duck->dropBook == false) && (book->scene() == GameScene) && (book->y() == 450))
    {
        GameScene->removeItem(book);
    }

}

void MainWindow::jumpRegulator()
{

    //cout<<tommy->jumpCounter<<endl;

    if (tommy->jumpCounter > 0 &&  tommy->jumpCounter < 359)
        clearFocus();

    else if(tommy->jumpCounter == -1 || tommy->jumpCounter == 359)
    {
        if (tommy->jumpCounter == 359)
            tommy->jumpCounter = -1;

        setFocus();
    }

}

void MainWindow::tommyJump()
{
            //cout<<tommy->jumpCounter<<endl;
            int Tx = tommy->x();

            if(tommy->isJumping)
            {
                tommy->moveBy(.15,-1);
                tommy->jumpCounter++;

                if (tommy->jumpCounter == 150)
                {
                    tommy->isJumping = false;
                    tommy->isFalling = true;
                }
            }

            if (tommy->isFalling)
            {
                tommy->moveBy(.15,1);
                tommy->jumpCounter++;

                if (tommy->jumpCounter == 300)
                {
                    tommy->isJumping = false;
                    tommy->isFalling = false;
                }
            }

            if ( (tommy->isJumping == false) && (tommy->isFalling == false) && (Tx != 400))
            {
                tommy->moveBy(-.75,0);
                tommy->jumpCounter++;
            }

}

void MainWindow::fireballShoot()
{
    if (devil->shootFireball == true)
    {
        int Fx = fireball->x();
        if (Fx > 100)
        {
            fireball->moveBy(-1.5, 0);
        }
        if (Fx == 100 && (fireball->scene() == GameScene))
        {
            //cout<<"Done"<<endl;
            GameScene->removeItem(fireball);
            devil->shootFireball = false;
        }
    }
}


void MainWindow::bookDrop()
{
    if (duck->dropBook == true)
    {
        int BookY = book->y();
        if (BookY < 450)
        {
            book->moveBy(0,1);
        }
        if (BookY == 450 && (book->scene() == GameScene))
        {
            GameScene->removeItem(book);
            duck->dropBook = false;
        }
    }
}


void MainWindow::pause()
{
    timer->stop();
}

void MainWindow::exit()
{
    close();
    qApp->quit();
}

MainWindow::~MainWindow()
{

}
