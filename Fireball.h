#ifndef FIREBALL_H
#define FIREBALL_H

#include "GameObject.h"
#include <iostream>
using namespace std;

class Fireball:public GameObject
{
public:
    Fireball();
    ~Fireball();
    bool moving;
    int GIFcounter;

};

#endif // FIREBALL_H