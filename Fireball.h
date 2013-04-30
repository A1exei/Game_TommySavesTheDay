#ifndef FIREBALL_H
#define FIREBALL_H

#include "GameObject.h"
#include <iostream>
using namespace std;


/** Fireball object that is released horizontally from devil object */
class Fireball:public GameObject
{
public:
    Fireball();
    ~Fireball();
    bool moving;
    int GIFcounter;
    int type_;
    int ObjectType();

};

#endif // FIREBALL_H
