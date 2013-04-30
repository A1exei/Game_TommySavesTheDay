#ifndef BOOK_H
#define BOOK_H

#include "GameObject.h"
#include <iostream>
using namespace std;

/** Projectile object that is released by the duck. Oject falls vertically from the top of the screen */
class Book:public GameObject
{
public:
    Book();
    ~Book();
    bool moving;
    int GIFcounter;
    int type_;
    int ObjectType();
};


#endif // BOOK_H
