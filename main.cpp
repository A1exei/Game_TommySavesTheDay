#include <QDesktopWidget>
#include <QApplication>
#include <QtGui/QApplication>
#include "mainwindow.h"


int main(int argc, char *argv[])
{

  QApplication app(argc, argv);

  MainWindow window;
  window.show();
  window.resize(1000,600);

  return app.exec();
}
