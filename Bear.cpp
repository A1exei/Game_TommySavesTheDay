#include "Bear.h"

Bear::Bear()
{
    pic = new QPixmap("Images/BEAR_1.png");
    pic2 = new QPixmap("Images/BEAR_2.png");
    scaled = pic->scaled( 150, 150, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    scaled2 = pic2->scaled( 150, 150, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    label = new QLabel(this);
    label->setPixmap(scaled);

    label->setAutoFillBackground(true);
    QPalette pal = label->palette();
    pal.setColor(QPalette::Window, QColor(Qt::white));
    label->setPalette(pal);

    timer = new QTimer(this);
    timer->setInterval(400);
    timer->start();

    connect(timer, SIGNAL(timeout()), this, SLOT( movement() ) );

}

void Bear::movement()
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



Bear::~Bear()
{
}

