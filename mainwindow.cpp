#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    scene = new QGraphicsScene;
    MainView = new QGraphicsView(scene);
    GameScene  = new QGraphicsScene();
    GameView = new QGraphicsView(GameScene);

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

    Layout->addWidget(GameView);

    tommy  = new Tommy();
    bear = new Bear();

    GameScene->addWidget(bear);


    timer  = new QTimer(this);
    timer->setInterval(15);
    timer->start();

    connect(timer, SIGNAL(timeout()), this, SLOT( objectAnimate() ));

}



void MainWindow::objectAnimate()
{
    int x = bear->x();
    int y = bear->y();

    bear->move(x-1,y);

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
