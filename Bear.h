#ifndef BEAR_H
#define BEAR_H

#include "GameObject.h"
#include <iostream>
using namespace std;

class Bear : public GameObject
{

    public:
        Bear();
        ~Bear();  
        bool moving;
        int GIFcounter;
        int type_;
        int ObjectType();


};

#endif // BEAR_H
