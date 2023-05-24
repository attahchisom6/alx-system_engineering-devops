#include "game.h"
#include "map.h"

#define PI 3.14159
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

bool initCamera(SDL_Event event, SDL_Renderer *renderer)
{
    float cameraAngle = 0.0;

    switch (event.key.keysym.sym) {
        case SDLK_LEFT:
            cameraAngle -= 0.5;
            break;
        case SDLK_RIGHT:
            cameraAngle += 0.5;
            break;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    return true;
}

void raycasted(SDL_Renderer *renderer)
{
    int x;
    int wallHeight;
    int **map = renderMap();
    float cameraX = 5.0;
    float cameraY = 5.0;
    float cameraAngle = 0.0;

    /* raycasting and drawing wall */
    for (x = 0; x < SCREEN_WIDTH; x++) {
        float rayAngle = (cameraAngle - 0.5 * PI) + ((float)x / SCREEN_WIDTH) * PI;
        float rayDirX = cos(rayAngle);
        float rayDirY = sin(rayAngle);

        /* performing the draw */
        float distanceToWall = 0.0;
        bool hitWall = false;
        bool hitBoundary = false;

        /* increment size for ray casting */
        float stepSize = 0.1;
        float currentX = cameraX;
        float currentY = cameraY;

        while (!hitWall && distanceToWall < 10.0) {
            int testX = (int)(currentX + distanceToWall * rayDirX + 0.5);
            int testY = (int)(currentY + distanceToWall * rayDirY + 0.5);

            distanceToWall += stepSize;

            if (testX < 0 || testX >= SCREEN_WIDTH || testY < 0 || testY >= SCREEN_HEIGHT) {
                hitWall = true;
                distanceToWall = 10.0;
            } else if (map[testY][testX] == 1) {
                hitWall = true;

                bool boundary = false;

                while (!boundary && distanceToWall < 10.0) {
                    float boundX = currentX + distanceToWall * rayDirX;
                    float boundY = currentY + distanceToWall * rayDirY;

                    distanceToWall += stepSize;

                    if (boundX < 0 || boundX >= SCREEN_WIDTH || boundY < 0 || boundY >= SCREEN_HEIGHT) {
                        boundary = true;
                    } else if (map[(int)(boundY + 0.5)][(int)(boundX + 0.5)] != 1) {
                        boundary = true;
                        hitBoundary = true;
                    }
                }
            }
        }

        /* measure wall height based on the distance to wall */
        wallHeight = (int)(SCREEN_HEIGHT / distanceToWall);

        /* set wall color and line segment */
        SDL_SetRenderDrawColor(renderer, hitBoundary ? 255 : 128, 128, 128, 255);
        SDL_RenderDrawLine(renderer, x, (SCREEN_HEIGHT - wallHeight) / 2, x, (SCREEN_HEIGHT + wallHeight) / 2);
    }

    freeMap(map);
}

bool createWindowRenderer(void)
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "SDL initialization failed: %s\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("Raycasting", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (window == NULL) {
        fprintf(stderr, "Window creation failed: %s\n", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        fprintf(stderr, "Renderer creation failed: %s\n", SDL_GetError());
        return false;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    SDL_Event event;
    bool quit = false;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            } else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    quit = true;
                } else {
                    initCamera(event, renderer);
                    raycasted(renderer);
                    SDL_RenderPresent(renderer);
                }
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return true;
}
