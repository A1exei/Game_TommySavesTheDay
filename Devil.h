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
    int GIFcounter;
    int type_;
    int ObjectType();
};

#endif // DEVIL_H
