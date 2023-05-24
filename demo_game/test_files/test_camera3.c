#include "../Headers/sources.h"

void free_map(int **map);

/**
 * Init_camera - function that handles camera rotation
 * @event: handles things like keyboard presses from the player
 * @renderer: SDL Object to render stuff to the screen
 *
 * Return: true on success
 */
bool Init_camera(SDL_Event event, SDL_Renderer *renderer)
{
	float cameraAngle = 0.0;

	switch (event.key.keysym.sym)
	{
		case SDLK_LEFT:
			cameraAngle -= 0.5;
			break;
		case SDLK_RIGHT:
			cameraAngle += 0.5;
			break;
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	return (true);
}

/**
 * create_map - creates a map with predefined values
 *
 * Return: allocated map
 */
int **create_map(void)
{
	int **map = malloc(ROWS * sizeof(int *));
	int k, p;

	for (k = 0; k < ROWS; k++)
	{
		map[k] = malloc(COLUMNS * sizeof(int));
	}

	int initialMap[ROWS][COLUMNS] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
		{1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	for (p = 0; p < ROWS; p++)
	{
		for (k = 0; k < COLUMNS; k++)
		{
			map[p][k] = initialMap[p][k];
		}
	}

	return (map);
}

/**
 * free_map - frees memory allocated to the map
 * @map: double pointer to the map matrix
 *
 * Return: void
 */
void free_map(int **map)
{
	int k;

	for (k = 0; k < ROWS; k++)
		free(map[k]);
	free(map);
}

/**
 * raycasted - performs raycasting and draws walls
 * @renderer: the SDL renderer
 *
 * Return: void
 */
void raycasted(SDL_Renderer *renderer)
{
	int x;
	int wallHeight;
	int **map = create_map();
	float cameraX = 5.0;
	float cameraY = 5.0;
	float cameraAngle = 0.0;

	/* Raycasting and drawing walls */
	for (x = 0; x < SCREEN_WIDTH; x++)
	{
		float rayAngle = (cameraAngle - 0.5 * PI) + ((float)x / SCREEN_WIDTH) * PI;
		float rayDirX = cos(rayAngle);
		float rayDirY = sin(rayAngle);

		/* Performing the draw */
		float distanceToWall = 0.0;
		bool hitWall = false;
		bool hitBoundary = false;

		/* Increment size for ray casting */
		float stepSize = 0.1;
		float currentX = cameraX;
		float currentY = cameraY;

		while (!hitWall && distanceToWall < 10.0)
		{
			int testX = (int)(currentX + distanceToWall * rayDirX);
			int testY = (int)(currentY + distanceToWall * rayDirY);

			if (testX < 0 || testX >= SCREEN_WIDTH || testY < 0 ||
					testY >= SCREEN_HEIGHT)
			{
				hitWall = true;
				distanceToWall = 10.0;
			}
			else if (map[testX][testY] == 1)
			{
				hitWall = true;
				bool boundary = false;

				while (!boundary && distanceToWall < 10.0)
				{
					int boundX = (int)(currentX + distanceToWall * rayDirX);
					int boundY = (int)(currentY + distanceToWall * rayDirY);

					if (boundX < 0 || boundX >= SCREEN_WIDTH || boundY < 0 ||
							boundY >= SCREEN_HEIGHT)
					{
						boundary = true;
					}
					else if (map[boundX][boundY] != 1)
					{
						boundary = true;
						hitBoundary = true;
					}

					distanceToWall += stepSize;
				}
			}

			distanceToWall += stepSize;
		}

		/* Measure wall height based on the distance to wall */
		wallHeight = (int)(SCREEN_HEIGHT / distanceToWall);

		/* Set wall color and draw line segment */
		SDL_SetRenderDrawColor(renderer, hitBoundary ? 255 : 128, 128, 128, 255);
		SDL_RenderDrawLine(renderer, x, (SCREEN_HEIGHT - wallHeight) / 2, x,
				(SCREEN_HEIGHT + wallHeight) / 2);
	}

	/* Update the renderer */
	SDL_RenderPresent(renderer);
	free_map(map);
}
