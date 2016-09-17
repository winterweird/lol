#include <stdio.h>
#include "gamelogic.h"
#include "gameconstants.h"
#include "winconapi.h"

unsigned int gameloop() {
    int ch; // variable to store keyboard input in
    unsigned int score = 0;

    int playerXPos = CONSOLE_WIDTH / 2;
    int playerYPos = 0;
    int playerSpeed = PLAYER_SPEED; // this is kinda dumb D:

    // Left hand are variables; right hand are base constants
    // The variables will change as the game progresses, but in
    // level 1 they are identical to the ones on the right hand
    int zombieSpawnDelay     = ZOMBIE_SPAWN_DELAY;
    int zombieDelayDecrement = ZOMBIE_DELAY_DECR;
    int zombieSpawnCountdown = zombieSpawnDelay;
    int zombieStepDelay      = ZOMBIE_STEP_DELAY;

    // variables for dynamic difficulty
    double spawnDelaySubtract = 0;
    double stepDelaySubtract = 0;

    Zombie* zombieList = NULL; // no zombies yet!

    // As earlier: Left hand are variables, right hand are constants
    int bulletStepDelay = BULLET_STEP_DELAY;
    int bulletRange     = BULLET_RANGE;

    Bullet bullet;  // this is our magical teleporting bullet
    // initial setup:
    bullet.range = bulletRange;
    bullet.stepDelay = bulletStepDelay;
    bullet.sprite = '*';
    resetBullet(&bullet); // handles the rest of the setup

    char playing = 1;
    while (playing) {
        if (kbhit()) {
            ch = getch();
            switch (ch) {
                case 'a': // move left
                    jumpTo(playerXPos, playerYPos); printf(" ");
                    playerXPos -= playerXPos - playerSpeed > 0 ? playerSpeed : 0;
                    break;
                case 'd': // move right
                    jumpTo(playerXPos, playerYPos); printf(" ");
                    playerXPos += playerXPos + playerSpeed < CONSOLE_WIDTH ? playerSpeed : 0;
                    break;
                case ' ': // fire
                    resetBullet(&bullet); // unblit and reset fields
                    // put it just in front of the player and activate
                    bullet.position.x = playerXPos;
                    bullet.position.y = playerYPos + 1;
                    bullet.active = 1;
                    blitBullet(bullet); // because it won't blit until next step
                    break;
                case CHARACTER_ESCAPE:
                    playing = 0;
                    break;
            }
        }

        // if it's time to spawn a zombie, do that
        if (zombieSpawnCountdown < 0) {
            zombieList = spawnZombie(zombieList, zombieStepDelay);
            zombieSpawnCountdown = zombieSpawnDelay;
        }
        else {
            // TO ZERO, THE COUNTDOWN HAS BEGUN \m/
            zombieSpawnCountdown -= zombieDelayDecrement;
        }
        
        updateBullet(&bullet);
        char zombieWasHit = hitZombie(zombieList, bullet);
        if (zombieWasHit) {
            // some part of the zombie was hit
            int x = bullet.position.x, y = bullet.position.y;
            if (zombieWasHit > 0) {
                // zombie was headshot
                zombieList = killZombie(zombieList, x, y);
                score++;
                updateMechanicsVariables(score,
                                         &zombieSpawnDelay,
                                         &spawnDelaySubtract,
                                         &zombieStepDelay,
                                         &stepDelaySubtract);
            }
            resetBullet(&bullet);
        }
        updateZombies(zombieList);
        if (zombieReachedTheTop(zombieList)) {
            playing = 0;
        }

        // blit the player
        jumpTo(playerXPos, playerYPos);
        printf("X");
        fflush(stdout); // might not be necessary, but I doubt it hurts much

        Sleep(MS_DELAY);
    }
    freeAllZombies(zombieList);
    return score;
}

char hitZombie(Zombie* zombie, Bullet bullet) {
    // NOTE: This function is a bad, bad function because it
    // has the side effect of changing a zombie's sprite if it
    // hits its arm, despite looking like it should simply
    // return a boolean. It is NOT OKAY TO CODE LIKE THIS. Don't
    // ever tell anyone I taught you how.
    while (zombie != NULL) {
        if (zombie->position.y == bullet.position.y) {
            if (zombie->position.x == bullet.position.x) return 1;
            if (zombie->position.x - 1 == bullet.position.x) {
                // hit left arm
                zombie->leftArm = ' '; return -1;
            }
            if (zombie->position.x + 1 == bullet.position.x) {
                // hit right arm
                zombie->rightArm = ' '; return -1;
            }
        }
        zombie = zombie->next;
    }
    return 0;
}

void updateZombies(Zombie* zombieList) {
    Zombie* currentZombie = zombieList;
    while (currentZombie != NULL) {
        if (currentZombie->stepCountDown < 0) {
            currentZombie->stepCountDown = currentZombie->stepDelay;
            unblitZombie(currentZombie);
            currentZombie->position.y--;
            blitZombie(currentZombie);
        } else {
            currentZombie->stepCountDown--;
        }
        currentZombie = currentZombie->next;
    }
}

char zombieReachedTheTop(Zombie* zombieList) {
    Zombie* currentZombie = zombieList;
    while (currentZombie != NULL) {
        if (currentZombie->position.y == 0) {
            return 1;
        }
        currentZombie = currentZombie->next;
    }
    return 0;
}

void updateMechanicsVariables(int score, int* zspd, double* spds, int* zstd, double* stds) {
    // variable names shortened for terseness:
    // zspd = zombieSpawnDelay
    // spds = spawnDelaySubtract
    // zstd = zombieStepDelay
    // stds = stepDelaySubtract
    *spds += 2.0 + 5.0/score;
    *stds  += 1.0 + 3.0/score;
    *zspd = ZOMBIE_SPAWN_DELAY - (int)(*spds);
    *zstd = ZOMBIE_STEP_DELAY - (int)(*stds);
}