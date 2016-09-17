#include <stdio.h>
#include "bullet.h"
#include "winconapi.h"

void unblitBullet(Bullet b) {
    jumpTo(b.position.x, b.position.y);
    printf(" ");
}
void blitBullet(Bullet b) {
    jumpTo(b.position.x, b.position.y);
    printf("%c", b.sprite);
}
void resetBullet(Bullet* b) {
    unblitBullet(*b);
    b->active = 0; b->position.x = 0; b->position.y = 0;
    b->stepCountDown = b->stepDelay;
    b->rangeCountDown = b->range;
}
void updateBullet(Bullet* b) {
    if (b->active) {
        if (b->rangeCountDown < 0) {
            resetBullet(b);
        }
        else if (b->stepCountDown < 0) {
            unblitBullet(*b);
            b->position.y++;
            blitBullet(*b);
            b->rangeCountDown--;
            b->stepCountDown = b->stepDelay;
        }
        else {
            b->stepCountDown--;
        }
    }
}