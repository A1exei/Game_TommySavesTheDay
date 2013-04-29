#ifndef TREE_H
#define TREE_H

#include "GameObject.h"
#include <iostream>
using namespace std;

class Tree: public GameObject
{
public:
    Tree();
    ~Tree();

    bool moving;
    bool isJumping;
    bool isFalling;
    int GIFcounter;
    int type_;
    int ObjectType();
};

#endif // TREE_H
