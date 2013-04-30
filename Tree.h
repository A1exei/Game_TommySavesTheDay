#ifndef TREE_H
#define TREE_H

#include "GameObject.h"
#include <iostream>
using namespace std;


/** Tree object that jumps in randomized arcs around the screen */
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
