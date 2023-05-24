#include "game.h"
#include "camera.h"
#include "map.h"

bool create_window_renderer(SDL_Renderer *renderer)
{
    SDL_Window *window = NULL;


    renderer = NULL;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr, "Could not initialize SDL2; SDL Error: %s\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow(
        "My first game - written 9 months into my ALX course",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN
    );
    if (!window)
    {
        fprintf(stderr, "Failed to create window; SDL Error: %s\n", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        fprintf(stderr, "Failed to create renderer; SDL Error: %s\n", SDL_GetError());
        return false;
    }

    game_loop();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return true;
}

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
                Init_camera(event);
        }
    }
}

