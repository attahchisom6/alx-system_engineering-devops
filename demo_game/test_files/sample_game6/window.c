#include "game.h"

SDL_Window *window;
SDL_Renderer *renderer;
color_t *colorBuffer;
SDL_Texture *colorBufferTexture;

bool createWindowRenderer(void)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr, "Failed to initialize SDL: %s\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    if (window == NULL)
    {
        fprintf(stderr, "Failed to create SDL window: %s\n", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == NULL)
    {
        fprintf(stderr, "Failed to create SDL renderer: %s\n", SDL_GetError());
        return false;
    }

    colorBuffer = (color_t *)malloc(sizeof(color_t) * SCREEN_WIDTH * SCREEN_HEIGHT);

    if (colorBuffer == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for color buffer\n");
        return false;
    }

    colorBufferTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING,
                                           SCREEN_WIDTH, SCREEN_HEIGHT);

    if (colorBufferTexture == NULL)
    {
        fprintf(stderr, "Failed to create SDL texture: %s\n", SDL_GetError());
        return false;
    }

    return true;
}

void clearColorBuffer(color_t color)
{
    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++)
    {
        colorBuffer[i] = color;
    }
}

void renderColorBuffer(void)
{
    SDL_UpdateTexture(colorBufferTexture, NULL, colorBuffer, SCREEN_WIDTH * sizeof(color_t));
    SDL_RenderCopy(renderer, colorBufferTexture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

void drawPixel(int x, int y, color_t color)
{
    if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
    {
        colorBuffer[(SCREEN_WIDTH * y) + x] = color;
    }
}

/*void destroyWindowRenderer(void)
{
    free(colorBuffer);
    SDL_DestroyTexture(colorBufferTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
	}*/
