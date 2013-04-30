#ifndef TOMMY_H
#define TOMMY_H

#include "GameObject.h"
#include <iostream>
using namespace std;

/** Main character object. This object (Tommy) stays in the middle of the game screen as other objects
    come towards it. Tommy can jump, move left or move right to avoid the oncoming objects. If he gets
    hit by an object, he will blink and lose health*/
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
