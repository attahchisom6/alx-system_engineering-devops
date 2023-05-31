#include "game.h"

static SDL_Window *window;
static SDL_Renderer *renderer;
static color_t *colorBuffer;
static SDL_Texture *colorBufferTexture;

/**
 * createWindowRenderer - creates a window and a render our game
 * to the wundow
 *
 * Return: void
 */

bool createWindowRenderer(void)
{
	SDL_DisplayMode displayMode;

	int fullScreenWidth, fullScreenHeight;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		fprintf(stderr, "failed to initialize SDL; SDL Error: %s\n",
				SDL_GetError());
		return (false);
	}

	SDL_GetCurrentDisplayMode(0, &displayMode);
	fullScreenWidth = displayMode.w;
	fullScreenHeight = displayMode.h;

	window = SDL_CreateWindow(
			"my first game wriiten 9 month into my Alx course", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, fullScreenWidth, fullScreenHeight,
			SDL_WINDOW_SHOWN
		);
	if (!window)
	{
		fprintf(stderr, "Could not insitialize window; SDL Error: %s\n",
				SDL_GetError());
		return (false);
	}

	renderer = SDL_CreateRenderer(window, -1, 1);
	if (!renderer)
	{
		fprintf(stderr, "Rendering failed, SDL Error: %s\n", SDL_GetError());
		return (false);
	}

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	colorBuffer = malloc(SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(color_t));
	colorBufferTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32,
			SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);
	return (true);
}

/**
 * close - close / destroy all session of sdl runnin process
 *
 * Return: void
 */

/*void close(void)
{
	free(colorBuffer);
	SDL_DestroyTexture(colorBufferTexture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}*/

/**
 * clearColorBuffer - clear buffer for every framw
 * @color: new color to set;
 *
 * Return: void
 */

void clearColorBuffer(color_t color)
{
	int k;

	for (k = 0; k < SCREEN_WIDTH * SCREEN_HEIGHT; k++)
	{
		colorBuffer[k] = color;
	}
}

/**
 * renderColorBuffer - render color for each frame
 *
 * Return: void
 */

void renderColorBuffer(void)
{
	SDL_UpdateTexture(
			colorBufferTexture,
			NULL,
			colorBuffer,
			(int)(SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(color_t))
		);
	SDL_RenderCopy(renderer, colorBufferTexture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

/**
 * drawPixel - assign color to each pixel
 * @color: color to assign to each pixel
 * @x: x coordinate of the pixel
 * @y: y cordinate of the pixel
 *
 * Return: void
 */

void drawPixel(int x, int y, color_t color)
{
	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
		colorBuffer[(SCREEN_WIDTH * y) + x] = color;
}
