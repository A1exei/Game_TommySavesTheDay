#ifndef DEVIL_H
#define DEVIL_H

#include "GameObject.h"
#include <iostream>
using namespace std;

class Devil:public GameObject
{
public:
    Devil();
    ~Devil();
    bool moving;
    bool shootFireball;
    int GIFcounter;
};

#endif // DEVIL_H
