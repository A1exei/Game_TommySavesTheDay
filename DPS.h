#ifndef DPS_H
#define DPS_H

#include "GameObject.h"
#include <iostream>
using namespace std;

class DPS : public GameObject
{

    public:
        DPS();
        ~DPS();

        bool moving;
        int GIFcounter;


};

#endif // DPS_H
