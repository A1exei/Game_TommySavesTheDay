#ifndef BEAR_H
#define BEAR_H

#include "GameObject.h"
#include <iostream>
using namespace std;

/** Bear object that runs through the scene. Main character must jump to avoid it */
class Bear : public GameObject
{

    public:
        Bear();
        ~Bear();  
        bool moving;
        int GIFcounter;

        /** Object Type number */
        int type_;

        /** Returns type number */
        int ObjectType();


};

#endif // BEAR_H
