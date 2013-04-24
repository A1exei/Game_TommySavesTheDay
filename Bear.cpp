#include "Bear.h"

Bear::Bear()
{
    BearPic = new QPixmap("Images/BEAR_1.png");
    BearPic2 = new QPixmap("Images/BEAR_2.png");
    BearScaled = BearPic->scaled( 150, 150, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    BearScaled2 = BearPic2->scaled( 150, 150, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    BearLabel = new QLabel(this);
    BearLabel->setPixmap(BearScaled);

    BearLabel->setAutoFillBackground(true);
    QPalette pal = BearLabel->palette();
    pal.setColor(QPalette::Window, QColor(Qt::white));
    BearLabel->setPalette(pal);

    BearTimer = new QTimer(this);
    BearTimer->setInterval(400);
    BearTimer->start();

    connect(BearTimer, SIGNAL(timeout()), this, SLOT( movement() ) );

}

void Bear::movement()
{
    if (moving == true)
    {
         BearLabel->setPixmap(BearScaled);
         moving = false;
    }
    else
    {
        BearLabel->setPixmap(BearScaled2);
        moving = true;
    }
}



Bear::~Bear()
{
}

