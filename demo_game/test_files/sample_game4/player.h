#ifndef PLAYER_H
#define PLAYER_H

#include "constants.h"
/**
 * struct Player_s - a structure containing information about the player
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

typedef struct Player_s
{
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

/*input functions */
void pressedKeys(SDL_Event event);
void releasedKeys(SDL_Event event);
void handleInput(void);

#endif /* PLAYER_H */
