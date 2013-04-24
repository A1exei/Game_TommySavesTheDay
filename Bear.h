#ifndef BEAR_H
#define BEAR_H

#include "GameObject.h"
#include <iostream>
using namespace std;

class Bear : public GameObject
{
    Q_OBJECT
public:
    Bear();
    ~Bear();
    QPixmap* BearPic;
    QPixmap* BearPic2;
    QPixmap BearScaled;
    QPixmap BearScaled2;
    QLabel* BearLabel;
    QTimer* BearTimer;
    bool moving;


public slots:
    void movement();
};

#endif // BEAR_H
