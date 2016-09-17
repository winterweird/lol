#ifndef BULLET_H
#define BULLET_H

#include "point.h"

typedef struct _Bullet {
    Point position;
    int stepDelay;
    int stepCountDown;
    int range;
    int rangeCountDown;
    char active;
    char sprite;
} Bullet;

void unblitBullet(Bullet b);
void blitBullet(Bullet b);
void resetBullet(Bullet* b);
void updateBullet(Bullet* b);

#endif /* BULLET_H */