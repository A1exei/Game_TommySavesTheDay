#include "Backdrop.h"


Backdrop::Backdrop()
{
    BackgroundPic = new QPixmap("Images/cityBackground.png");
    BackgroundScaled = BackgroundPic->scaled( 1500, 550, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    setPixmap(BackgroundScaled);
    type_ = -1;

}

int Backdrop::ObjectType()
{
    return type_;
}

Backdrop::~Backdrop()
{

}
