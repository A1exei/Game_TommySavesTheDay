#include "Tommy.h"

Tommy::Tommy()
{
    /*pic = new QPixmap("Images/HORSE.png");
    pic2 = new QPixmap("Images/HORSE_2.png");
    scaled = pic->scaled( 100, 100, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    scaled2 = pic2->scaled( 100, 100, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    setPixmap(scaled);  */


    isJumping = false;
    GIFcounter = 0;
    jumpCounter = 0;


}


void Tommy::movement()
{
    /*if (GIFcounter%30 == 0)
    {
        if (moving == true)
        {
             setPixmap(scaled);
             moving = false;
             GIFcounter = 0;
        }
        else
        {
            setPixmap(scaled2);
            moving = true;
            GIFcounter = 0;
        }


    }
    GIFcounter++;   */
}


void Tommy::jump()
{

    int Tx = this->x();
    int Ty = this->y();

    if (jumpCounter > 156)
    {
        isJumping = false;
        jumpCounter = 0;
    }

    if (isJumping )
    {

        this->setPos(Tx,Ty-1);
        jumpCounter++;
    }


}


Tommy::~Tommy()
{
}
