#include "MyHeader.h"

/**
 * create_window - function to create a window for our game application
 * and a renderer for our game
 *
 * return: 0 on success
 */

bool create_window_renderer()
{
	SDL_window *window;
	SDL_renderer *renderer;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "SDL could not initialize! SDL Error: %s\n", 
