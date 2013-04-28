#ifndef DUCK_H
#define DUCK_H

#include "GameObject.h"
#include <iostream>
using namespace std;

class Duck: public GameObject
{
public:
    Duck();
    ~Duck();
    bool moving;
    int GIFcounter;
    bool dropBook;
};

#endif // DUCK_H
