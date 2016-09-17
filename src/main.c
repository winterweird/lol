#include <stdio.h>         // printf and such
#include <stdlib.h>        // srand
#include <time.h>          // time
#include "winconapi.h"     // jumpTo; getX; getY; (though I'm not sure I'm using those two...)
#include "reallyrandom.h"  // randint
#include "gamelogic.h"     // gameloop
#include "gameconstants.h" // what do you think?

int main() {
    // seed the rng
    srand(time(NULL));

    char keepPlaying = 1;
    while (keepPlaying) {
        system("cls"); // yes, yes, I know this is bad practice...

        unsigned int score = gameloop();

        jumpTo(0, CONSOLE_HEIGHT + 3);
        printf("You were overwhelmed by zombies!\n");
        printf("Final score: %u\n", score);
        printf("Do you want to play again? (y/n)\n");

        int answer;
        do {
            answer = getch();
            keepPlaying = (answer == 'y' || answer == 'Y');
        } while (!(answer == 'y' || answer == 'Y' || answer == 'n' || answer == 'N'));
    }
    
}