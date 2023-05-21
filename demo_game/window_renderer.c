#include "MyHeaders/sources.h"

/**
 * create_window_renderer - function to create a window for our
 * game application
 * and a renderer for our game
 *
 * Return: true on success
 */

bool create_window_renderer(void)
{
	SDL_Window *window = NULL;
	SDL_Renderer renderer = NULL;

	if (Init_SDL(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "Could not initialize SDL2; SDL Error: %s\n",
				SDL_GetError());
		return (false);
	}

	window = SDL_CreateWindow(
			"My first game; written 9 months into my ALX course",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
			SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (!window)
	{
		fprintf(stderr, "failed to initialize window; SDL Error: %s\n",
				SDL_GetError());
		return (false);
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer)
	{
		fprintf(stderr, "Could not initiate renderer; SDL Error: %s\n",
				SDL_GetError());
		return (false);
	}
	return (true);
}
