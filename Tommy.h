#ifndef TOMMY_H
#define TOMMY_H

#include "GameObject.h"
#include <iostream>
using namespace std;

class Tommy : public GameObject
{

    public:
        Tommy();
        ~Tommy();
        /*QPixmap* pic;
        QPixmap* pic2;
        QPixmap scaled;
        QPixmap scaled2;   */
        bool moving;
        bool isJumping;
        int GIFcounter;
        int jumpCounter;


    public slots:
        void movement();
        void jump();
};

#endif // TOMMY_H
