#include "game.h"

/**
 * initCamera - initialize camera for the player
 * @event: situations suchvas pressing the keyboard
 * @renderer: object to render items to our screen
 * @player: the player
 *
 * Return: true on sucess 
 */

bool initCamera(SDL_Event event, SDL_Renderer *renderer, Player *player)
{
    float cameraAngle = 0.0;

    switch (event.key.keysym.sym)
    {
        case SDLK_LEFT:
            player->direction -= 0.1; // Adjust player rotation left
            break;
        case SDLK_RIGHT:
            player->direction += 0.1; // Adjust player rotation right
            break;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    return (true);
}

void raycasted(SDL_Renderer *renderer, Player *player)
{
    int x;
    int wallHeight;
    int **map = renderMap();
    float cameraX = player->x;
    float cameraY = player->y;
    float cameraAngle = player->direction;

    for (x = 0; x < SCREEN_WIDTH; x++)
    {
        float rayAngle = (cameraAngle - 0.5 * PI) + ((float)x / SCREEN_WIDTH) * PI;
        float rayDirX = cos(rayAngle);
        float rayDirY = sin(rayAngle);

        float distanceToWall = 0.0;
        bool hitWall = false;
        bool hitBoundary = false;

        float stepSize = 0.1;
        float currentX = cameraX;
        float currentY = cameraY;

        while (!hitWall && distanceToWall < 10.0) {
            int testX = (int)(currentX + distanceToWall * rayDirX + 0.5);
            int testY = (int)(currentY + distanceToWall * rayDirY + 0.5);

            distanceToWall += stepSize;

            if (testX < 0 || testX >= SCREEN_WIDTH || testY < 0 || testY >= SCREEN_HEIGHT)
	    {
                hitWall = true;
                distanceToWall = 10.0;
            }
	    else if (map[testY][testX] == 1)
	    {
                hitWall = true;

                bool boundary = false;

                while (!boundary && distanceToWall < 10.0) {
                    float boundX = currentX + distanceToWall * rayDirX;
                    float boundY = currentY + distanceToWall * rayDirY;

                    distanceToWall += stepSize;

                    if (boundX < 0 || boundX >= SCREEN_WIDTH || boundY < 0 || boundY >= SCREEN_HEIGHT) {
                        boundary = true;
                    }
		    else if (map[(int)(boundY + 0.5)][(int)(boundX + 0.5)] != 1)
		    {
                        boundary = true;
                        hitBoundary = true;
                    }
                }
            }
        }

        wallHeight = (int)(SCREEN_HEIGHT / distanceToWall);

        SDL_SetRenderDrawColor(renderer, hitBoundary ? 255 : 128, 128, 128, 255);
        SDL_RenderDrawLine(renderer, x, (SCREEN_HEIGHT - wallHeight) / 2, x, (SCREEN_HEIGHT + wallHeight) / 2);
    }

    freeMap(map);
}


/**
 * close - closes or clea the window or renderer
 * @window: object to display game data
 * @renderer: serves to render data to the window
 *
 * Return: void
 */

void close(SDL_Window *window, SDL_Renderer *renderer, Player *player)
{
	if (window)
		SDL_DestroyWindow(window);
	if (renderer)
		SDL_DestroyRenderer(renderer);
	if (player)
		destroyPlayer(player);
}

/**
 * createWindowRender - function to create a window and a renderer
 * @window: creates a display object for our game
 * @renderer: render content to the window
 *
 * Return: true when objects are successfully rendered to the window
 */

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
    Player *player = createPlayer(5.0, 5.0, 0.0);

    while (!quit)
    {
        while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
                	quit = true;
		else if (event.type == SDL_KEYDOWN)
		{
                	if (event.key.keysym.sym == SDLK_ESCAPE)
				quit = true;
			else
			{
                		initCamera(event, renderer, player);
				raycasted(renderer, player);
                    		SDL_RenderPresent(renderer);
                	}
		}
	}
    }
    close(window, renderer, player);
    SDL_Quit();
    return (true);
}
