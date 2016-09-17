#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "point.h"


typedef struct _Zombie {
    struct _Zombie* next;
    Point position;
    int stepCountDown;
    int stepDelay;
    // sprites:
    char leftArm;
    char head;
    char rightArm;
    int health; // might not use this part
} Zombie;

Zombie* spawnZombie(Zombie* zombieList, int stepDelay);
Zombie* killZombie(Zombie* zombieList, int x, int y);
void freeAllZombies(Zombie* zombieList);

// requires winconapi.h
void unblitZombie(Zombie* zombie);
void blitZombie(Zombie* zombie);

#endif /* ZOMBIE_H */