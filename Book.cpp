#include "Book.h"

Book::Book()
{
    GIFcounter = 0;
    type_ = 7;
}

int Book::ObjectType()
{
    return type_;
}

Book::~Book()
{

}
