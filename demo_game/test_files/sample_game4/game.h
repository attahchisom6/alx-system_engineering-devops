#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include <SDL2/SDL.h>
#include "player.h"
#include "map.h"
#include "visuals.h"
#include <math.h>
#include <stdlib.h>
#include <stdint.h>

#define PI 3.1416926535897
#define TWO_PI 6.2831853071795
#define SCREEN_WIDTH (COLUMNS * titleSize)
#define SCREEN_HEIGHT (ROWS * titleSize)
#define SCALE_FACTOR 0.25
#define NUM_RAYS SCREEN_WIDTH
#define FOV_ANGLE PI / 3

#endif /* GAME_H */
