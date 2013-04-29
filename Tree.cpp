#include "Tree.h"

Tree::Tree()
{
    GIFcounter = 0;
    isJumping = false;
    isFalling = false;
    type_ = 3;
}

int Tree::ObjectType()
{
    return type_;
}

Tree::~Tree()
{
}
