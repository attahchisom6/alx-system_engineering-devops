#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

bool create_window_renderer(void)
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr, "SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("My first game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        fprintf(stderr, "Failed to create window! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        fprintf(stderr, "Failed to create renderer! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    // Raycasting and Drawing Walls
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Set background color (ground/ceil)
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set wall color
    // Perform raycasting and draw walls using SDL_RenderDrawLine or other rendering functions

    SDL_RenderPresent(renderer);

    // Modify Map
    // Implement code to modify the map (e.g., using an array of integers or characters)

    // Camera Angle
    // Implement code to change the camera angle

    // Event Loop
    bool quit = false;
    SDL_Event event;
    while (!quit)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
            // Handle other events as needed
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return true;
}

int main(void)
{
    if (!create_window_renderer())
    {
        fprintf(stderr, "Failed to create window and renderer!\n");
        return 1;
    }

    return 0;
}
