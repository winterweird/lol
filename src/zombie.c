#include "zombie.h"
#include "winconapi.h"
#include "gameconstants.h"
#include "reallyrandom.h"
#include <stdlib.h>
#include <stdio.h>

Zombie* spawnZombie(Zombie* zombieList, int stepDelay) {
    // add a zombie to the top of the linked list zombieList
    // return new head of zombieList
    Zombie* zmb = malloc(sizeof *zmb);
    zmb->next = zombieList;
    zmb->position.y = CONSOLE_HEIGHT; // start just outside the screen
    zmb->position.x = randint(CONSOLE_WIDTH - 3) + 1;
    zmb->stepDelay = stepDelay;
    zmb->stepCountDown = zmb->stepDelay;
    zmb->head = 'o'; zmb->leftArm = 'l'; zmb->rightArm = 'l';
    return zmb;
}

Zombie* killZombie(Zombie* zombieList, int x, int y) {
    // go through the zombie list, check if any zombies
    // have coordinates x and y, and if so, kill 'em
    // (that includes freeing the memory).
    // then return the (new?) head of the list
    Zombie* currentZombie = zombieList; // start at the head
    Zombie* prev = NULL;

    while (currentZombie != NULL) {
        if (currentZombie->position.x == x && currentZombie->position.y == y) {
            // kill the zombie
            unblitZombie(currentZombie);
            Zombie* nextZombie = currentZombie->next;
            if (prev != NULL) {
                // join the two halves of the linked list
                prev->next = nextZombie;
            } else {
                // the top zombie was the one hit. Make nextZombie
                // the new head
                zombieList = nextZombie;
            }
            free(currentZombie);
            return zombieList;
        }
        prev = currentZombie;
        currentZombie = currentZombie->next;
    }
    return zombieList;
}

// requires winconapi.h
void unblitZombie(Zombie* zombie) {
    if (zombie->position.y < CONSOLE_HEIGHT) {
        jumpTo(zombie->position.x - 1, zombie->position.y);
        printf("   ");
    }
}

void blitZombie(Zombie* zombie) {
    if (zombie->position.y < CONSOLE_HEIGHT) {
        jumpTo(zombie->position.x - 1, zombie->position.y);
        printf("%c%c%c", zombie->leftArm, zombie->head, zombie->rightArm);
    }
}
void freeAllZombies(Zombie* zombieList) {
    Zombie* current = zombieList, *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}