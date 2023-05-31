#include "game.h"

/**
 * pressedKeys - process input when a key is pressed down
 * @event: union that contain structures for different event types
 *
 * Return: void
 */

void pressedKeys(SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_ESCAPE)
		gameRunning = false;
	if (event.key.keysym.sym == SDLK_UP)
		player.walkDirection = +1;
	if (event.key.keysym.sym == SDLK_w)
		player.walkDirection = +1;
	if (event.key.keysym.sym == SDLK_DOWN)
		player.walkDirection = -1;
	if (event.key.keysym.sym == SDLK_s)
		player.walkDirection = -1;
	if (event.key.keysym.sym == SDLK_RIGHT)
		player.turnDirection = +1;
	if (event.key.keysym.sym == SDLK_d)
		player.turnDirection = +1;
	if (event.key.keysym.sym == SDLK_LEFT)
		player.turnDirection = -1;
	if (event.key.keysym.sym == SDLK_a)
		player.turnDirection = -1;
}

/**
 * releasedKeys - handles event when the key is released
 * @event: unoin that contain structures that for dealing with different
 * situation
 *
 * Return: void
 */

void releasedKeys(SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_UP)
		player.walkDirection = 0;
	if (event.key.keysym.sym == SDLK_w)
		player.walkDirection = 0;
	if (event.key.keysym.sym == SDLK_DOWN)
		player.walkDirection = 0;
	if (event.key.keysym.sym == SDLK_s)
		player.walkFirection = 0;
	if (event.key.keysym.sym == RIGHT)
		player.turnDirection = 0;
	if (event.key.keysym.sym == SDLK_d)
		player.turnDirection = 0;
	if (event.key.keysym.sym == SDLK_LEFT)
		player.turnDirection = 0;
	if (event.key.keysym.sym == SDLK_a)
		player.turnDirection = 0;
}

/**
 * handleInput - handles input from the user as events
 *
 * Return: void
 */

void handleInput(void)
{
	SDL_Event event;

	SDL_PollEvent(&event);

	if (event.type == SDL_QUIT)
		gameRunning = false;
	else if (event.type == SDL_KEYDOWN)
		pressedKeys(event);
	else if (event.type == SDL_KEYUP)
		releasedKeys(event);
}
