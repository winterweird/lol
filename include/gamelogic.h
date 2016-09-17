#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "bullet.h"
#include "zombie.h"

char hitZombie(Zombie* zombie, Bullet bullet);
void updateZombies(Zombie* zombieList);
char zombieReachedTheTop(Zombie* zombieList);
unsigned int gameloop();
void updateMechanicsVariables(int score, int*, double*, int*, double*);

#endif /* GAMELOGIC_H */