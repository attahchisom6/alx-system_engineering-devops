#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define MAP_WIDTH 10
#define MAP_HEIGHT 10

int map[MAP_WIDTH][MAP_HEIGHT] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

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

    // Camera Angle
    float cameraX = 5.0; // X position of the camera
    float cameraY = 5.0; // Y position of the camera
    float cameraAngle = 0.0; // Angle of the camera

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
            else if (event.type == SDL_KEYDOWN)
            {
                // Adjust camera angle based on arrow key presses
                switch (event.key.keysym.sym)
                {
                    case SDLK_LEFT:
                        cameraAngle -= 0.1;
                        break;
                    case SDLK_RIGHT:
                        cameraAngle += 0.1;
                        break;
                }
            }
        }

        // Clear the renderer
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Raycasting and Drawing Walls
        for (int x = 0; x < SCREEN_WIDTH; x++)
        {
            // Calculate ray angle and direction
            float rayAngle = (cameraAngle - 0.5 * 3.14159) + ((float)x / SCREEN_WIDTH) * 3.14159;
            float rayDirX = cos(rayAngle);
            float rayDirY = sin(rayAngle);

            // Perform raycasting and draw walls
            float distanceToWall = 0.0;
            bool hitWall = false;
            bool hitBoundary = false;

            float stepSize = 0.1; // Increment size for ray casting
            float currentX = cameraX;
            float currentY = cameraY;

            while (!hitWall && distanceToWall < 10.0)
            {
                distanceToWall += stepSize;
                int testX = (int)(currentX + rayDirX * distanceToWall);
                int testY = (int)(currentY + rayDirY * distanceToWall);

                // Check if ray has hit a wall
                if (testX < 0 || testX >= MAP_WIDTH || testY < 0 || testY >= MAP_HEIGHT)
                {
                    hitWall = true;
                    distanceToWall = 10.0;
                }
                else if (map[testX][testY] == 1)
                {
                    hitWall = true;

                    // Check if ray has hit a boundary between two walls
                    bool boundary = false;
                    while (!boundary && distanceToWall < 10.0)
                    {
                        distanceToWall += stepSize;
                        int nextX = (int)(currentX + rayDirX * distanceToWall);
                        int nextY = (int)(currentY + rayDirY * distanceToWall);

                        if (nextX < 0 || nextX >= MAP_WIDTH || nextY < 0 || nextY >= MAP_HEIGHT)
                        {
                            boundary = true;
                        }
                        else if (map[nextX][nextY] != 1)
                        {
                            boundary = true;
                            hitBoundary = true;
                        }
                    }
                }
            }

            // Calculate wall height based on distance
            int wallHeight = (int)(SCREEN_HEIGHT / distanceToWall);

            // Set wall color and draw wall segment
            SDL_SetRenderDrawColor(renderer, hitBoundary ? 255 : 128, 128, 128, 255);
            SDL_RenderDrawLine(renderer, x, SCREEN_HEIGHT / 2 - wallHeight / 2, x, SCREEN_HEIGHT / 2 + wallHeight / 2);
        }

        // Update the renderer
        SDL_RenderPresent(renderer);
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
