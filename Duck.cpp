#include "Duck.h"

Duck::Duck()
{
    GIFcounter = 0;
    type_ = 6;
}

int Duck::ObjectType()
{
    return type_;
}

Duck::~Duck()
{
}
