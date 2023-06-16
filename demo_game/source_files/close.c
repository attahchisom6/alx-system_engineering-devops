#include "../Headers/sources.h"

/**
 * close - functions in this particular source file will aims
 * to destroy all running processes or infinite loop
 * @window: window we want to display our game content
 * @renderer: An object that renders items to our window
 *
 * Return: void
 */

/*void close(SDL_Window *window, SDL_Renderer *renderer)
{
	if (window)
		SDL_DestroyWindow(window);
	if (renderer)
		SDL_DestroyRenderer(renderer);

	quit the sdl sub-system*/
	/*SDL_QUIT();
}*/

/**
 * game_loop - handles all process running, while the game is still alive
 *
 * Return: false on success
 */

void game_loop(void)
{
	bool quit = false;
	SDL_Event event;

	while (!quit)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				quit = true;

			else if (event.type == SDL_KEYDOWN)
				Init_camera(event, NULL);
		}
	}
}
