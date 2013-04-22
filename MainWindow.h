#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#define WINDOW_MAX_X 500
#define WINDOW_MAX_Y 500



class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void show();
    void start();
    void exit();
    
    QTimer* timer;


private:
    QGraphicsScene *scene;
    QGraphicsScene *BoardScene;
    QGraphicsView *MainView;
    QGraphicsView *BoardView;

private slots:
    void exit();
    void start();


#endif // MAINWINDOW_H
