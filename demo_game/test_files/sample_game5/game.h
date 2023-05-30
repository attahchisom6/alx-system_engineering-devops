#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include <SDL2/SDL.h>
#include "player.h"
#include "rays.h"
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
#define FOV_ANGLE PI / 3
#define PROJ_PLANE ((SCREEN_WIDTH / 2) / tan(FOV_ANGLE / 2))
#define NUM_RAYS SCREEN_WIDTH
	

/**
 * Player - a structure containing information about the player
 * @x: X coordinate of the player
 * @y: y cordinate of the player
 * @width: player width
 * @height:player height
 * @turnDirection: turn direction
 * @walkDirection: walk direction
 * @rotationAngle: player rotation angle
 * @walkSpeed: walk speed
 * @turnSpeed: turn speed
 */

typedef struct Player_s {
    float x;
    float y;
    float width;
    float height;
    int turnDirection;
    float walkDirection;
    float rotationAngle;
    float walkSpeed;
    float turnSpeed;
} Player_t;

extern Player_t player;

/**
 * struct ray_s - struct store data of ray directions
 * @wallHitX: wall hit x coordinate
 * @wallHitY: wall hit y coordinate
 * @rayAngle: ray angle
 * @distanceToWall: distance to wall
 * @isVerticalHit: verify if the hit is vertical
 * @wallHitContent: wall hit content
 */

typedef struct ray_s
{
	float wallHitX;
	float wallHitY;
	float rayAngle;
	float distanceToWall;
	bool isVerticalHit;
	int wallHitContent;
} ray_t;

extern ray_t rays[NUM_RAYS];

/*ray function*/
void HorzIntersection(float rayAngle);
void VertIntersection(float rayAngle);
void cast_ray(float rayAngle, int rayId);
void cast_all_rays(void);
void renderRays(void);

#define ROWS 9
#define COLUMNS 10
#define titleSize 64

int **renderMap(void);
void freeMap(int **map);

#define NUM_TEXTURES 8

/**
 * struct texture_s - renders the texture of a surface to a window
 * @width: width of the texture
 * @height: height of the texture
 * @textureBuffer - pointer to texture buffer
 * @upngTexture: pointer to upng texture
 *
 * description: handles dcreen texture
 */

typedef uint64_t color_t;

typedef struct texture_s
{
	int width;
	int height;
	color_t *textureBuffer;
	/*upng_t *upngTexture;*/
} texture_t;

extern texture_t wallTextures[NUM_TEXTURES];

/* visual functions */
bool createWindowRenderer(void);
void close(void);
void clearColorBuffer(color_t color);
void renderColorBuffer(void);
void drawPixel(color_t color, int x, int y);

/*wall, floor and ceiling functions*/
void changeColorItensity(color_t *color, float factor);
void renderFloor(int BottomTopPixel, color_t *texelColor, int p);
void renderCeiling(int wallTopPixel, color_t *texelColor, int p);
void renderWall(void);

#endif /* GAME_H */
