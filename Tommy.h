#ifndef TOMMY_H
#define TOMMY_H

#include "GameObject.h"
#include <iostream>
using namespace std;

class Tommy : public GameObject
{
    Q_OBJECT
    public:
        Tommy();
        ~Tommy();
        QPixmap* pic;
        QPixmap* pic2;
        QPixmap scaled;
        QPixmap scaled2;
        QLabel* label;
        QTimer* timer;
        bool moving;


    public slots:
        void movement();
};

#endif // TOMMY_H
