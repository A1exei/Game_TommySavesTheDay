#ifndef DUCK_H
#define DUCK_H

#include "GameObject.h"
#include <iostream>
using namespace std;


/** Duck object that flys through the scene and drops projectiles onto main character */
class Duck: public GameObject
{
public:
    Duck();
    ~Duck();
    bool moving;
    int GIFcounter;
    int type_;
    int ObjectType();
};

#endif // DUCK_H
