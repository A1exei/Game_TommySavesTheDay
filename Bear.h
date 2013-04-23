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
    QPixmap* pic;
    QPixmap* pic2;
    QPixmap scaled;
    QPixmap scaled2;
    QLabel* label;
    QTimer* timer;
    bool moving;


public slots:
    void movement();
};

#endif // BEAR_H
