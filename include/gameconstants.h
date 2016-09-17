#ifndef GAMECONSTANTS_H
#define GAMECONSTANTS_H

#define MS_DELAY 10
#define CONSOLE_WIDTH 80
#define CONSOLE_HEIGHT 25
#define CHARACTER_ESCAPE 27

#define MOVE_LEFT 'a'
#define MOVE_RIGHT 'd'
#define FIRE_GUN ' '
#define QUIT_GAME CHARACTER_ESCAPE

// GAME CONSTANTS
#define PLAYER_SPEED 1 // shouldn't really exceed this with my current implementation
#define BULLET_RANGE 10
#define BULLET_STEP_DELAY 50
#define ZOMBIE_SPAWN_DELAY 400
#define ZOMBIE_STEP_DELAY 100
#define ZOMBIE_DELAY_DECR 1

#endif /* GAMECONSTANTS_H */