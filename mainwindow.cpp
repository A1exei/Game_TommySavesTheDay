#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setFocus();
    this->setFocusPolicy(Qt::StrongFocus);
    scene = new QGraphicsScene;
    MainView = new QGraphicsView(scene);
    GameScene  = new QGraphicsScene();
    GameView = new QGraphicsView(GameScene);
    GameScene->setSceneRect(20,20, 600, 400);

    MainView->setWindowTitle( "Tommy Saves The Day");
    MainView->setFixedSize( 700, 500 );
    Layout = new QVBoxLayout();
    ToolBar = new QToolBar("Tommy Saves the Day");
    Layout->addWidget(ToolBar);
    MainView->setLayout(Layout);

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

    GameScene->addWidget(bear);
    GameScene->addWidget(tommy);
    tommy->move(0,300);
    bear->move(300,250);

    timer  = new QTimer(this);
    timer->setInterval(15);
    timer->start();

    connect(Start, SIGNAL(clicked()), this, SLOT( start() ));
    connect(Quit, SIGNAL(clicked()), this, SLOT( exit() ));
    connect(timer, SIGNAL(timeout()), this, SLOT( objectAnimate() ));



}


void MainWindow::start()
{

}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //cout<<"Test";
    switch(event->key())
    {
        case Qt::Key_Space:
            cout<<"Space!"<<endl;
            break;

    }

}


void MainWindow::objectAnimate()
{
    //int Tx = tommy->x();
   // int Ty = tommy->y();
   // tommy->move(0,0);

    int Bx = bear->x();
    int By = bear->y();
    if (Bx < -170)
        bear->move(700,250);
    else
        bear->move(Bx-1,By);
}

void MainWindow::show()
{
    MainView->show();
}

void MainWindow::exit()
{
    close();
    qApp->quit();
}

MainWindow::~MainWindow()
{

}
