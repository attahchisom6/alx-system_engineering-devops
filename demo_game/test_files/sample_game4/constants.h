#ifndef CONSTANTS_H
#define CONSTANTS_H

#define PI 3.1416926535897
#define TWO_PI 6.2831853071795
#define titleSize 64
#define ROWS 9
#define COLUMNS 10
#define SCREEN_WIDTH (COLUMNS * titleSize)
#define SCREEN_HEIGHT (ROWS * titleSize)
#define NUM_TEXTURES 8
#define SCALE_FACTOR 0.25
#define FOV_ANGLE PI / 3
#define PROJ_PLANE ((SCREEN_WIDTH / 2) / tan(FOV_ANGLE / 2))
#define NUM_RAYS SCREEN_WIDTH

#endif /*CONSTANT NUMBERS */
