#ifndef BOOK_H
#define BOOK_H

#include "GameObject.h"
#include <iostream>
using namespace std;

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
