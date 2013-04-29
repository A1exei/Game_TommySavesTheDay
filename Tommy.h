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
        bool moving;
        bool flashing;
        bool isJumping;
        bool isFalling;
        int GIFcounter;
        int hurtCounter;
        int jumpCounter;
        int type_;
        int ObjectType();


    public slots:
        void movement();
        void jump();
};

#endif // TOMMY_H
