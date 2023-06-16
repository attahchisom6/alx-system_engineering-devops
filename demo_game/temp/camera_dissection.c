#include "../Headers/sources.h"

void free_map(int **map);

/**
 * Init_camera - function that handles camera rotation
 *
 * Return: true on success
 */

bool Init_camera(SDL_Event event, SDL_Renderer *render)
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

	SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
	SDL_RenderClear(render);
	return (true);
}

/**
 * renderMap - defines a map or the world the player moves in
 *
 * Return: an array of nunbers
 */

int **renderMap(void)
{
	int **map = malloc(ROWS * sizeof(int *));
	int k, p;

	for (k = 0; k < ROWS; k++)
	{
		map[k] = malloc(COLUMNS * sizeof(int));
	}

	int InitialMap[ROWS][COLUMNS] = {
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
			map[p][k] = InitialMap[p][k];
		}
	}
	return (map);
}

 
/**
 * raycasted - setting sail to make our drawing raycasted
 *
 * Return: we will see
 */
void raycasted(SDL_Renderer *renderer)
{
	int x;
	int wallHeight;
	int **map = renderMap();
	float cameraX = 5.0;
	float cameraY = 5.0;
	float cameraAngle = 0.0;

	/*raycasting and drawing wall*/
	for (x = 0; x < SCREEN_WIDTH; x++)
	{
		float rayAngle = (cameraAngle - 0.5 * PI) + ((float)x / SCREEN_WIDTH) * PI;
		float rayDirX = cos(rayAngle);
		float rayDirY = sin(rayAngle);

		/*performing the draw*/
		float distanceToWall = 0.0;
		bool hitWall = false;
		bool hitBoundary = false;

		/*increment size for ray casting*/
		float stepSize = 0.1;
		float currentX = cameraX;
		float currentY = cameraY;

		while (!hitWall && distanceToWall < 10.0)
		{
			int testX;
			int testY;

			distanceToWall += stepSize;
			testX = (int)(currentX + distanceToWall * rayDirX);
			testY = (int)(currentY + distanceToWall * rayDirY);

			if (testX < 0 || testX >= SCREEN_WIDTH || testY < 0 || testY >= SCREEN_HEIGHT)
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
					int BoundX;
					int BoundY;

					distanceToWall += stepSize;
					BoundX = (int)(currentX + distanceToWall * rayDirX);
					BoundY = (int)(currentY + distanceToWall * rayDirY);

					if (BoundX < 0 || BoundX >= SCREEN_WIDTH || BoundY < 0 || BoundY >= SCREEN_HEIGHT)
					{
						boundary = true;
					}
					else if (map[BoundX][BoundY] != 1)
					{
						boundary = true;
						hitBoundary = true;
					}
				}
			}
		}

		/*measure  wall height based on the distance to wall*/
		wallHeight = (int)(SCREEN_HEIGHT / distanceToWall);

		/*set wall color and line segment*/
		SDL_SetRenderDrawColor(renderer, hitBoundary ? 255 : 128, 128, 128, 255);
		SDL_RenderDrawLine(renderer, x, (SCREEN_HEIGHT - wallHeight) / 2, x, (SCREEN_HEIGHT + wallHeight) / 2);
	}
	/*update the renderer*/
	SDL_RenderPresent(renderer);
	free_map(map);
}

/**
 * free_map - frees memory allocated to the map vector
 * @map: A double pointer to the map matrix
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
