#include "Tommy.h"

Tommy::Tommy()
{
    pic = new QPixmap("Images/HORSE.png");
    pic2 = new QPixmap("Images/HORSE_2.png");
    scaled = pic->scaled( 100, 100, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    scaled2 = pic2->scaled( 100, 100, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    label = new QLabel(this);
    label->setPixmap(scaled);


    timer = new QTimer(this);
    timer->setInterval(400);
    timer->start();

    connect(timer, SIGNAL(timeout()), this, SLOT( movement() ) );

}

void Tommy::movement()
{
    if (moving == true)
    {
        label->setPixmap(scaled);
         moving = false;
    }
    else
    {
        label->setPixmap(scaled2);
        moving = true;
    }
}



Tommy::~Tommy()
{
}
