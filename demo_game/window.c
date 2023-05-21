#include "MyHeader/sources.h"

/**
 * create_window_renderer - function to create a window for our
 * game application
 * and a renderer for our game
 *
 * Return: true on success
 */

bool create_window_renderer(void)
{
	SDL_window *window;
	SDL_renderer *renderer;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		return (false);
	}

	window = SDL_CreateWindow("My first game", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WONDOW_SHOWN);
	if (window == NULL)
	{
		fprintf(stderr, "failed to initialize window! SDL Error: %s\n",
				SDL_GetError());
		return (false);
	}
	else
	{
		screenSurface = SDL_GetWindowSurface(window);
		fill_Rect = SDL_Fill_Rect(screenSurface, NULL,
				SDL_Map(screensurface->format, 0xff, 0xff, 0xff));
		SDL_Update_WindowSurface(window);

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (render == NULL)
		{
			fprintf(stderr, "Renderer could not be created! SDL Error: %s\n",
					SDL_GetError());
			return (false);
		}
	}
	return (true);
}
