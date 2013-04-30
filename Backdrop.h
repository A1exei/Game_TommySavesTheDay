#ifndef BACKDROP_H
#define BACKDROP_H

#include "GameObject.h"
#include <iostream>
using namespace std;

/** Background image of the game, object is made to scroll across the scene
    so as to simulate movement of main character through a city */
class Backdrop : public GameObject
{
    public:
        Backdrop();
        ~Backdrop();

        /** Object Image pixmap */
        QPixmap* BackgroundPic;

        QPixmap BackgroundScaled;

        int ObjectType();

        /** Object Type Number */
        int type_;

};

#endif // BACKDROP_H


