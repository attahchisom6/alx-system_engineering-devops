#include "../Headers/sources.h"

/**
 * camera - function that handles camera rotation
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
 * Return an array of nunbers
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
}

 
/**
 * raycasting - setting sail to make our drawing raycasted
 *
 * Return: we will see
 */
void raycasted(void)
{
	int x;
	int wallHeight;
	int map = renderMap();
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
			testX = currentX + distanceToWall * rayDirX;
			testY = currentY + distanceToWall * rayDirY;

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
					float BoundX;
					float BoundY;

					distanceToWall += stepSize;
					BoundX = currentX + distanceToWall * rayDirX;
					BoundY = currentY + distanceToWall * rayDirY;

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
		wallHeight = (int)(SCREEN_HIEGHT / distanceToWall);

		/*set wall color and line segment*/
		SDL_SetRenderDrawColor(renderer, hitBoundary ? 255 : 128, 128, 128, 255);
		SDL_RenderDrawLine(renderer, x, (SCREEN_HEIGHT - wallHieght) / 2, x, (SCREEN_HEIGHT + wallHeight) / 2);
	}
	/*update the renderer*/
	SDL_RenderPresent(render);
}

/**
 * free_map
 */

free_map()
{
	for (
