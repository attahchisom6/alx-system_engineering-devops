#include "game.h"

Player_t player;
bool gameRunning = false;
int tickLastFrame

/**
 * setUpGame - initializes data needed for game to run
 *
 * Return: void
 */

void setUpGame(void)
{
	player.x = SCREEN_WIDTH / 2;
	player.y = SCTEEN_HEIGHT / 2;
	player.width = 5;
	player.height = 30;
	player.turnDirection = 0;
	player.walkDirection = 0;
	player.rotationAngle = PI / 2;
	player.walkSpeed = 100;
	player.turnSpeed = PI / 4;
	// wallTextureReady();
}

/**
 * updateGame - update game delta time, ticks last frame, player moves and
 * raycasting
 *
 * Return: void
 */

void updateGame(void)
{
	float deltaTime;
	int timeToWait = FRAME_TIME_LENGHT - (SDL_GetTicks() - ticksLastFrame);

	if (timeToWait > 0 && timeToWait <=  FRAME_TIME_LENGHT)
		SDL_Delay(timeToWait);

	deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;
	ticksLastFrame = SDL_GetTicks();

	// movePlayer(deltaTime);
	// cast_all_rays();
}

/**
 * renderGame - calls all funcrions needed for unscreen rendering
 *
 * Return: void
 */

void render(void)
{
	// renderWall();
	// renderMap();
	// renderRays();
	// render player();
	renderColorBuffer();
}

/**
 * destroy - free wall texures and as well destroy windows
 *
 * Return: void
 */

void destroyGame(void)
{
	freeWallTexture();
	destroyWindow();
}

/**
 * main - function entry point
 *
 * Return: void
 */

int main(void)
{
	gameRunning = createWindowRender();

	setUpGame();
	while (gameRunning)
	{
		handleInput();
		updateGame();
		renderGame();
	}
	destroyGame();
	return (0);
}
