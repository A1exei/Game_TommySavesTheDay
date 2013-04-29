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
    leftPosition = false;
    GameScene->addItem(tommy);
    tommy->setPos(400,350);

    bearExists = false;
    BearCounter = 0;
    numBears = 0;
    MAX_BEARS = 3;

    srand( time(NULL));
    bearStartX = rand()%800 + 800;

    DPSexists = false;
    DPSlimit = 40;
    DPScounter = 0;

    treeExists = false;
    treeCounter = 0;

    devilExists  = false;
    devilCounter = 0;

    fireballExists = false;

    duckExists = false;
    duckCounter = 0;

    bookExists = false;
    /*
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
    book->setPos(200, DUCK_Y);    */



    connect(Start, SIGNAL(clicked()), this, SLOT( start() ));
    connect(Quit, SIGNAL(clicked()), this, SLOT( exit() ));
    connect(Pause, SIGNAL(clicked()), this, SLOT( pause() ));
    connect(timer, SIGNAL(timeout()), this, SLOT( imageRotate() ));
    connect(timer, SIGNAL(timeout()), this, SLOT( objectAnimate() ));
    connect(timer, SIGNAL(timeout()), this, SLOT( jumpRegulator() ));
    connect(timer, SIGNAL(timeout()), this, SLOT( tommyJump() ));
    connect(timer, SIGNAL(timeout()), this, SLOT( fireballShoot() ));
    connect(timer, SIGNAL(timeout()), this, SLOT( bookDrop() ));
    connect(timer, SIGNAL(timeout()), this, SLOT( tommyCollision() ));
    connect(timer, SIGNAL(timeout()), this, SLOT( addItems() ));
    setFocus();

}


void MainWindow::start()
{
    timer->start();
    tommy->setPixmap(HorseScaled);
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
                    if (tommy->jumpCounter == -1 || tommy->jumpCounter == 0)
                    {
                        if (tommy->x() > 380)
                        {
                            leftPosition = true;
                            tommy->moveBy(-60, 0);
                        }
                    }

            }
            break;

        case Qt::Key_Right:
         {
                    if (tommy->jumpCounter == -1 || tommy->jumpCounter == 0)
                    {
                        if (tommy->x() < 400)
                        {
                            leftPosition = false;
                            tommy->moveBy(60, 0);
                        }
                    }
         }
         break;

        default:
            QWidget::keyPressEvent(event);
    }

}


void MainWindow::objectAnimate()
{

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

 ////////////////////////////////////////////////
    for (unsigned int i=0; i<GameObjects.size(); i++)
    {

        if( (GameObjects[i]->ObjectType() == 1 ) && ( bearExists==true ) )     // Bear Movement
        {
            int Bx = GameObjects[i]->x();
            if (Bx > -120)
                GameObjects[i]->moveBy(-.75, 0);

            if (Bx == -120)
            {
                GameObjects[i]->setPos(1800,410);
            }
         }
         ///////////////////////////////////////////                       // DPS movement

        if( (GameObjects[i]->ObjectType() == 2 ) && ( DPSexists == true ) )
        {
            int DPSx = GameObjects[i]->x();
            if (DPSx < DPSlimit)
                GameObjects[i]->moveBy(.25, 0);
        }

        //////////////////////////////////////////                      // Tree movement

        if( (GameObjects[i]->ObjectType() == 3 ) && ( treeExists == true ) )
        {
             int TreeX = GameObjects[i]->x();
             //int TreeY = GameObjects[i]->y();
            // cout<<TreeY<<endl;
                if(treeIsJumping)
                    {
                        GameObjects[i]->moveBy(-1.5,-1.7);
                        treeJumpCounter++;

                        if (treeJumpCounter == 150)
                        {
                            treeIsJumping = false;
                            treeIsFalling = true;
                        }
                    }

                    if (treeIsFalling)
                    {
                        GameObjects[i]->moveBy(-1.5,1.7);
                        treeJumpCounter++;

                        if (treeJumpCounter == 300)
                        {
                            treeIsJumping = false;
                            treeIsFalling = false;
                        }
                    }

                    if ((treeIsJumping == false) && (treeIsFalling == false) )
                    {
                        treeIsJumping = true;
                        treeJumpCounter = 0;
                    }

                    if (TreeX < -120 )
                    {
                        srand( time(NULL));
                        treeStartX = rand()%900 + 900;
                        //cout<<"Tree StartX: "<<treeStartX<<endl;

                        GameObjects[i]->setPos(treeStartX, 410);
                        treeIsJumping = true;
                        treeIsFalling = false;
                        treeJumpCounter = 0;
                    }
            }
       ////////////////////////////////////////////////////
       if( (GameObjects[i]->ObjectType() == 4 ) && ( devilExists == true ) )
        {
                int Dx = GameObjects[i]->x();
                if (Dx > 650)
                    GameObjects[i]->moveBy(-1, 0);
                if (Dx == 650)
                {
                    shootFireball = true;
                    GameScene->addItem(fireball);
                    fireball->setPos(600, 400);
                    fireball->setPixmap(FireballScaled);
                    GameObjects[i]->setPos(2000,410);
                }
         }
       //////////////////////////////////////////////////////
       if( (GameObjects[i]->ObjectType() == 6 ) && ( duckExists == true ) )
        {
            int DuckX = GameObjects[i]->x();

            if (DuckX > -500)
                GameObjects[i]->moveBy(-2, 0);

            if (DuckX == 400)
            {
                dropBook = true;
                book->setPixmap(BookScaled);
                GameScene->addItem(book);
                book->setPos(400, DUCK_Y);
            }

            if (DuckX == -500)
            {
                GameObjects[i]->setPos(2300,DUCK_Y);
            }
        }

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
    for (unsigned int i=0; i<GameObjects.size(); i++)
    {

        if( (GameObjects[i]->ObjectType() == 1 ) && ( bearExists==true ) )
        {
                    if (GameObjects[i]->GIFcounter%42 == 0)
                    {
                        if (GameObjects[i]->moving == true)
                        {
                             GameObjects[i]->setPixmap(BearScaled);
                             GameObjects[i]->moving = false;
                             GameObjects[i]->GIFcounter = 0;
                        }
                        else
                        {
                            GameObjects[i]->setPixmap(BearScaled2);
                            GameObjects[i]->moving = true;
                            GameObjects[i]->GIFcounter = 0;
                        }
                    }
                    GameObjects[i]->GIFcounter++;
         }


            ///////////////////////////////////////////////////////
        if( (GameObjects[i]->ObjectType() == 2 ) && ( DPSexists == true ) )
        {
           if (GameObjects[i]->GIFcounter%40 == 0)
            {
                if (GameObjects[i]->moving == true)
                {
                     GameObjects[i]->setPixmap(DPSscaled1);
                     GameObjects[i]->moving = false;
                     GameObjects[i]->GIFcounter = 0;
                }
                else
                {
                    GameObjects[i]->setPixmap(DPSscaled2);
                    GameObjects[i]->moving = true;
                    GameObjects[i]->GIFcounter = 0;
                }
            }
            GameObjects[i]->GIFcounter++;

        }
           ///////////////////////////////////////////////////////
       if( (GameObjects[i]->ObjectType() == 3 ) && ( treeExists == true ) )
        {
           if (GameObjects[i]->GIFcounter%50 == 0)
            {
                if (GameObjects[i]->moving == true)
                {
                     GameObjects[i]->setPixmap(TreeScaled1);
                     GameObjects[i]->moving = false;
                     GameObjects[i]->GIFcounter = 0;
                }
                else
                {
                    GameObjects[i]->setPixmap(TreeScaled2);
                    GameObjects[i]->moving = true;
                    GameObjects[i]->GIFcounter = 0;
                }
            }
            GameObjects[i]->GIFcounter++;
        }
        //////////////////////////////////////////////////////
       if( (GameObjects[i]->ObjectType() == 4 ) && ( devilExists == true ) )
        {
           if (GameObjects[i]->GIFcounter%42 == 0)
            {
                if (GameObjects[i]->moving == true)
                {
                     GameObjects[i]->setPixmap(DevilScaled);
                     GameObjects[i]->moving = false;
                     GameObjects[i]->GIFcounter = 0;
                }
                else
                {
                    GameObjects[i]->setPixmap(DevilScaled2);
                    GameObjects[i]->moving = true;
                    GameObjects[i]->GIFcounter = 0;
                }
            }
            GameObjects[i]->GIFcounter++;
        }

        //////////////////////////////////////////////////////
       if (fireballExists == true)
       {
            if (shootFireball == true)
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

           /* else if ((shootFireball == false) && (fireballExists == true) && (fireball->x() == 100))
            {
                cout<<"Test"<<endl;
                GameScene->removeItem(fireball);
                fireballExists = false;
            }                                       */
        }
        ////////////////////////////////////////////////////////////////
       if (bookExists == true)
       {
            if (dropBook == true)
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
            /*else if ((dropBook == false) && (book->scene() == GameScene) && (book->y() == 450))
            {
                GameScene->removeItem(book);
            }     */
       }
    }
}

void MainWindow::jumpRegulator()
{


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


            //cout<<tommy->y()<<endl;
           // cout<<endl;


            if(tommy->isJumping)
            {
                tommy->moveBy(.15,-1.2);
                tommy->jumpCounter++;
                //cout<<Tx<<endl;

                if (tommy->jumpCounter == 150)
                {
                    //cout<<Tx<<endl;
                    tommy->isJumping = false;
                    tommy->isFalling = true;
                }
            }

            if (tommy->isFalling)
            {
                tommy->moveBy(.15,1.2);
                tommy->jumpCounter++;
                //cout<<Tx<<endl;

                if (tommy->jumpCounter == 300)
                {
                    //cout<<Tx<<endl;
                    tommy->isJumping = false;
                    tommy->isFalling = false;
                }
            }

            if (leftPosition != true)
            {
                if ( (tommy->isJumping == false) && (tommy->isFalling == false) && (Tx != 400))
                {
                    tommy->moveBy(-.75,0);
                    //cout<<Tx<<endl;
                    tommy->jumpCounter++;
                }
            }

            if (leftPosition == true)
            {
                if ( (tommy->isJumping == false) && (tommy->isFalling == false) && (Tx != 340))
                {

                        tommy->moveBy(-.75,0);
                        //cout<<Tx<<endl;
                        tommy->jumpCounter++;
                }
            }
}


void MainWindow::fireballShoot()
{

    if (shootFireball == true && fireballExists == true)
    {
        int Fx = fireball->x();
        if (Fx > 100)
        {
            fireball->moveBy(-1.5, 0);
        }
        if (Fx == 100 && fireballExists == true && fireball->scene() == GameScene)
        {
            GameScene->removeItem(fireball);
            shootFireball = false;
        }
    }


}


void MainWindow::bookDrop()
{
    if (dropBook == true && bookExists == true)
    {
        int BookY = book->y();
        if (BookY < 450)
        {
            book->moveBy(0,1);
        }
        if (BookY == 450 && (book->scene() == GameScene))
        {
            GameScene->removeItem(book);
            dropBook = false;
        }
    }

}


void MainWindow::tommyCollision()
{
    for (unsigned int i=0; i<GameObjects.size(); i++)
    {
        if( (GameObjects[i]->ObjectType() == 1 ) && ( bearExists==true ) )
        {
            if (tommy->collidesWithItem(GameObjects[i]) )
                {
                    if (tommy->hurtCounter%10 == 0)
                    {
                        if (tommy->flashing == true)
                        {
                             tommy->setPixmap(HorseScaled);
                             tommy->flashing = false;
                             tommy->hurtCounter = 0;
                        }
                        else
                        {
                            tommy->setPixmap(blank);
                            tommy->flashing = true;
                            tommy->hurtCounter = 0;
                        }

                        if (tommy->hurtCounter%60 == 0)
                        {
                            int health = HealthBar->value();
                            HealthBar->setValue(health - 1);
                            tommy->hurtCounter = 0;
                        }
                    }
                    tommy->hurtCounter++;
                }
         }
        /////////////////////////
        if( (GameObjects[i]->ObjectType() == 3 ) && ( treeExists==true ) )
        {
            if (tommy->collidesWithItem(GameObjects[i]) )
                {
                    if (tommy->hurtCounter%10 == 0)
                    {
                        if (tommy->flashing == true)
                        {
                             tommy->setPixmap(HorseScaled);
                             tommy->flashing = false;
                             tommy->hurtCounter = 0;
                        }
                        else
                        {
                            tommy->setPixmap(blank);
                            tommy->flashing = true;
                            tommy->hurtCounter = 0;
                        }

                        if (tommy->hurtCounter%40 == 0)
                        {
                            int health = HealthBar->value();
                            HealthBar->setValue(health - 1);
                            tommy->hurtCounter = 0;
                        }
                    }
                    tommy->hurtCounter++;
                }
      }
///////////////////////////////////////////////////////////////////////////
            if (fireballExists == true && tommy->collidesWithItem(fireball) )
                {
                    if (tommy->hurtCounter%10 == 0)
                    {
                        if (tommy->flashing == true)
                        {
                             tommy->setPixmap(HorseScaled);
                             tommy->flashing = false;
                             tommy->hurtCounter = 0;
                        }
                        else
                        {
                            tommy->setPixmap(blank);
                            tommy->flashing = true;
                            tommy->hurtCounter = 0;
                        }

                        if (tommy->hurtCounter%30 == 0)
                        {
                            int health = HealthBar->value();
                            HealthBar->setValue(health - 1);
                            tommy->hurtCounter = 0;
                        }
                    }
                    tommy->hurtCounter++;
                }
///////////////////////////////////////////////////////////////
                if (bookExists == true && tommy->collidesWithItem(book) )
                    {
                        if (tommy->hurtCounter%50 == 0)
                        {
                            if (tommy->flashing == true)
                            {
                                 tommy->setPixmap(HorseScaled);
                                 tommy->flashing = false;
                                 tommy->hurtCounter = 0;
                            }
                            else
                            {
                                tommy->setPixmap(blank);
                                tommy->flashing = true;
                                tommy->hurtCounter = 0;
                            }

                            if (tommy->hurtCounter%80 == 0)
                            {
                                int health = HealthBar->value();
                                HealthBar->setValue(health - 1);
                                tommy->hurtCounter = 0;
                            }
                        }
                        tommy->hurtCounter++;
                    }

}
}


void MainWindow::addItems()
{
    if (BearCounter % 2000 == 0 && numBears < MAX_BEARS+1)
    {
        bear = new Bear();
        BearPic = new QPixmap("Images/BEAR_1.png");
        BearPic2 = new QPixmap("Images/BEAR_2.png");
        BearScaled = BearPic->scaled( 80, 80, Qt::IgnoreAspectRatio, Qt::FastTransformation );
        BearScaled2 = BearPic2->scaled( 80, 80, Qt::IgnoreAspectRatio, Qt::FastTransformation );
        bear->setPixmap(BearScaled);
        GameScene->addItem(bear);
        bear->setPos(bearStartX,410);

        bearExists = true;
        GameObjects.push_back(bear);
        cout<<"Vector Size: "<<GameObjects.size()<<endl;
        BearCounter = 0;
        numBears++;
    }
    BearCounter++;

///////////////////////////////////////////////////////////////
    if (DPSexists == false)
    {
        DPScounter++;
    }
    if (DPScounter % 3000 == 0 && DPSexists == false)
     {
        dps = new DPS();
        DPSpic1 = new QPixmap("Images/DPS_1.png");
        DPSpic2 = new QPixmap("Images/DPS_3.png");
        DPSscaled1 = DPSpic1->scaled( 90, 150, Qt::IgnoreAspectRatio, Qt::FastTransformation );
        DPSscaled2 = DPSpic2->scaled( 90, 150, Qt::IgnoreAspectRatio, Qt::FastTransformation );
        dps->setPixmap(DPSscaled1);
        GameScene->addItem(dps);
        dps->setPos(-200,400);

        DPSexists = true;
        GameObjects.push_back(dps);
        cout<<"Vector Size: "<<GameObjects.size()<<endl;
     }
/////////////////////////////////////////////////////////////////
    if (treeExists == false)
    {
        treeCounter++;
    }

    if (treeCounter % 100 == 0 && treeExists == false)
     {
        tree = new Tree();
        TreePic1 = new QPixmap("Images/TREE_1.png");
        TreePic2 = new QPixmap("Images/TREE_2.png");
        TreeScaled1 = TreePic1->scaled( 80, 70, Qt::IgnoreAspectRatio, Qt::FastTransformation );
        TreeScaled2 = TreePic2->scaled( 80, 70, Qt::IgnoreAspectRatio, Qt::FastTransformation );
        tree->setPixmap(TreeScaled1);
        GameScene->addItem(tree);
        tree->setPos(1000,410);
        treeIsJumping = true;
        treeJumpCounter = 0;

        treeExists = true;
        GameObjects.push_back(tree);
        cout<<"Vector Size: "<<GameObjects.size()<<endl;
     }
/////////////////////////////////////////////////////////////////
    if (devilExists == false)
    {
        devilCounter++;
    }

    if (devilCounter % 4000 == 0  && devilExists == false)
    {
            devil = new Devil();
            DevilPic = new QPixmap("Images/DEVIL_1.png");
            DevilPic2 = new QPixmap("Images/DEVIL_2.png");
            DevilScaled = DevilPic->scaled( 90, 90, Qt::IgnoreAspectRatio, Qt::FastTransformation );
            DevilScaled2 = DevilPic2->scaled( 90, 90, Qt::IgnoreAspectRatio, Qt::FastTransformation );
            GameScene->addItem(devil);
            devil->setPos(1200,410);

            devilExists = true;
            GameObjects.push_back(devil);
            cout<<"Vector Size: "<<GameObjects.size()<<endl;


            fireball = new Fireball();
            FireballPic = new QPixmap("Images/FIREBALL_1.png");
            FireballPic2 = new QPixmap("Images/FIREBALL_2.png");
            FireballScaled = FireballPic->scaled( 45, 45, Qt::IgnoreAspectRatio, Qt::FastTransformation );
            FireballScaled2 = FireballPic2->scaled( 45, 45, Qt::IgnoreAspectRatio, Qt::FastTransformation );


            fireballExists = true;
            shootFireball = false;
           // GameObjects.push_back(fireball);
           // cout<<"Vector Size: "<<GameObjects.size()<<endl;

     }
/////////////////////////////////////////////////
    if (duckExists == false)
        duckCounter++;

    if (duckCounter % 5000 == 0 && duckExists == false)
    {
        duck = new Duck();
        DuckPic = new QPixmap("Images/DUCK.png");
        DuckScaled = DuckPic->scaled( 100, 90, Qt::IgnoreAspectRatio, Qt::FastTransformation );
        GameScene->addItem(duck);
        DUCK_Y = 100;
        duck->setPos(1500, DUCK_Y);
        duck->setPixmap(DuckScaled);

        duckExists = true;
        GameObjects.push_back(duck);
        cout<<"Vector Size: "<<GameObjects.size()<<endl;

        book = new Book();
        BookPic = new QPixmap("Images/POOP_1.png");
        BookScaled = BookPic->scaled( 20, 20, Qt::IgnoreAspectRatio, Qt::FastTransformation );
        BookPic2 = new QPixmap("Images/POOP_2.png");
        BookScaled2 = BookPic2->scaled( 20, 20, Qt::IgnoreAspectRatio, Qt::FastTransformation );

        bookExists = true;
        dropBook = false;

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
//remember to delete fireball and book
}
