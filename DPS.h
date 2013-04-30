#ifndef DPS_H
#define DPS_H

#include "GameObject.h"
#include <iostream>
using namespace std;


/** DPS object that moves onto screen later in the game and simulates pursuit of main character.
    The more object the character hits, the slower he becomes and the closer this object gets to him */
class DPS : public GameObject
{

    public:
        DPS();
        ~DPS();
        bool moving;
        int GIFcounter;
        int type_;
        int ObjectType();


};

#endif // DPS_H
