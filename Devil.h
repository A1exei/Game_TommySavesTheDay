#ifndef DEVIL_H
#define DEVIL_H

#include "GameObject.h"
#include <iostream>
using namespace std;


/** Devil object that runs onto screen at various intervals and shoots fireballs */
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
