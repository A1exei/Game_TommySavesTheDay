#include "MainWindow.h"


/** Allocates memory for all of the program's visual coponents, connects the buttons to actual functions behind
    the scenes.
    @param pointer to parent Widget item  */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

        scene = new QGraphicsScene();
        MainView = new QGraphicsView( scene );
        layout = new QGridLayout;
        gameInProgress = false;

        ///////////////// Main Window Properties //////////////////
        MainView->setFixedSize( WINDOW_MAX_X, WINDOW_MAX_Y );
        MainView->setWindowTitle( "Tommy Saves the Day");
        MainView->setLayout(layout);
        MainView->setFixedSize( 500, 500 );
      //  layout->setHorizontalSpacing(10);
        QFont a("Helvetica", 10);
        QFont b("Helvetica", 10, QFont::Bold);

        ////////////////  Buttons, Labels, etc.. //////////////////
       

        BoardScene = new QGraphicsScene;                    // Scene and view for the board
        BoardView = new QGraphicsView( BoardScene );


       

        ////////////////  Make new timer   ///////////////////
        timer  = new QTimer(this);
        timer->setInterval(4);


        ///////////////////   Add connections  ///////////////
        connect(Start, SIGNAL(clicked()), this, SLOT( start() ));
        connect(Quit, SIGNAL(clicked()), this, SLOT( exit() ));
        connect(timer, SIGNAL(timeout()), this, SLOT( tileAnimate() ));
        connect(Cheat, SIGNAL(clicked()), SolutionList, SLOT( clear() ));
        connect(Cheat, SIGNAL(clicked()), this, SLOT( runAlgorithm() ));



}

/** Starts the game */
void MainWindow::start()
{
 


}


/** Shows contents of the program window */
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

    delete Start;
    delete Quit;
    delete scene;
    delete MainView;
}
