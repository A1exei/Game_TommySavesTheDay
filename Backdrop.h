#ifndef BACKDROP_H
#define BACKDROP_H

#include "GameObject.h"
#include <iostream>
using namespace std;

class Backdrop : public GameObject
{
    public:
        Backdrop();
        ~Backdrop();
        QPixmap* BackgroundPic;
        QPixmap BackgroundScaled;

};

#endif // BACKDROP_H


