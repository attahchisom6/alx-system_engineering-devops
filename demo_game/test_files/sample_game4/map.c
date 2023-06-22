#include "game.h"

static const int map[ROWS][COLUMNS] = {
	{6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
	{6, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 6},
	{6, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 6, 0, 0, 0, 6, 0, 0, 0, 6},
	{6, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 6, 0, 7, 7, 0, 0, 0, 0, 6},
	{6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 7, 0, 6},
	{6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 6},
	{6, 0, 0, 0, 0, 0, 7, 7, 7, 0, 0, 1, 0, 0, 0, 0, 7, 7, 0, 6},
	{6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
	{6, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 1, 0, 6},
	{6, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 1, 0, 6},
	{6, 0, 0, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
	{6, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
	{6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}
};

/**
 * detectCollision - function to detect collision in the next player movement
 * @x: next xcollision or Hit cordinate
 * @y: next ycollision or Hit cordinate
 *
 * Return: true if the player is about to collide with a wall/boundary else
 * false
 */

bool detectCollision(float x, float y)
{
	int gridX, gridY;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return (true);
	gridX = floor(x / titleSize);
	gridY = floor(y / titleSize);

	return (map[gridX][gridY]);
}

/**
 * isInsideMap - check if a player is inside the map region
 * @x: player x coordinate
 * @y: player y coordinate
 *
 * Return: true if inside map, else false
 */

bool isInsideMap(float x, float y)
{
	if (x >= 0 || x < SCREEN_WIDTH || y >= 0 || y < SCREEN_HEIGHT)
		return (true);
	return (false);
}

/**
 * getMapContent - get the content of a map at a particular coordinate
 * @row: the rows
 * @col: the columns
 *
 * Return: content of the map at that specific point
 */

int getMapContent(int row, int col)
{
	return (map[row][col]);
}

/**
 * renderMap - renders map
 * @x: x coordinate
 * @y: y coordinate
 *
 * Return: map
 */

void renderMap(void)
{
	int k, p, tileX, tileY;
	color_t tileColor;

	for (p = 0; p < ROWS; p++)
	{
		for (k = 0; k < COLUMNS; k++)
		{
			tileX = k * titleSize;
			tileY = p * titleSize;
			tileColor = map[p][k] != 0  ? 0xFFFFFFFF : 0x00000000;
			drawRect(
				tileX * SCALE_FACTOR,
				tileY * SCALE_FACTOR,
				titleSize * SCALE_FACTOR,
				titleSize * SCALE_FACTOR,
				tileColor
			);
		}
	}
}