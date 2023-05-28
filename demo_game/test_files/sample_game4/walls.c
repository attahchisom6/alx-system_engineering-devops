#include "visuals.h"

/**
 * changeColorIntensity - function to unmask a color bit
 * and itensify it based on the intesity factor, it does
 * this by masking(hide because bit manipulation by 0 return 0) out all undesired colors,
 * then isolate the desired color and itensify it
 * @color: color itensity to change
 * @factor: itensity factor
 *
 * Return: void
 */

void changeColorIntensity(color_t color, float factor)
{
	color_t alpha  = (*color & 0xFF000000);
	color_t red = (*color & 0x00FF0000) * factor;
	color_t green = (*color & 0x0000FF00) * factor;
	color_t blue = (*color & 0x000000FF) * factor;

	color_t color = alpha | (red & 0x00FF0000) | (green & 0x0000FF00)
		| (blue & 0x000000FF);
}

/**
 * renderFloor - render floor projection
 * @wallBottompixel: The bottom pixel of the wall
 * @texelColor: texture color
 * @p: current element in the ray arraya
 *
 * Return: void
 */

void renderFloor(int wallBottomPixel, color_t *texelColor, int p)
{
	int y, texture_height, texture_width, textureOffSetX, textureOffsetY;
	float distance, ratio;

	texture_width = wallTextures[3].width;
	texture_height = wallTextures[3].height;

	for (y = wallBottomPixel - 1; y < SCREEN_HEIGHT; y++)
	{
		ratio = player.height / (y - SCREEN_HEIGHT / 2);
		distance = (ratio * PROJ_PLANE) / cos(rays[x].rayAngle - player.rotationAngle);

		textureOfSetX = (int)(abs(player.x + distance * cos(rays[x].rayAngle)));
		textureOffSetY = (int)(abs(player.y + distance * sin(rays[p].rayAngle)));

		textureOffSetX = (int)(abs(textureOffsetX * texture_width / 30) % texture_width);
		textureOffSetY = (int)(abs(textureOfSetY * texture_height / 30) % texture_height);

		*texelColor = wallTextures[4].textureBuffer[textureOffSetX + textureOffSetY * texture_width];
		drawPixel(*texelColor, p, y);
	}
}

/**
 * RenderCeiling - render the ceiling
 * @wallTopTexture: texture of the ceiling
 * @texelColor: texture color
 * @p:current element in the ray array
 *
 * Return: void
 */

void RenderCeiling(int wallTopTexture, color_t *texelColor, int p)
{
	int texture_height, texture_width, textureOffSetX, textureOffSetY;
	float distance, ratio;

	texture_width = wallTextures[3].width;
	texturw_height = wallTextures[3].height;

	for (p = 0; p < wallTopTexture; p++)
	{
		ratio = player.height / (y - SCREEN_HEIGHT / 2);
		distance = ratio * PROJ_PLANE / cos(rays[p].rayAngle - player.rotationAngle);

		textureOffSetX = (int)(abs(player.x - distance * cos(rays[p].rayAngle)));
		textureOffSetY = (int)(abs(player.y - distance * sin(rays[p].rayAngle)));

		textureOffSetX = (int)(abs(textureOffSetX * texture_width / 40) % texture_width);
		textureOffSetY = (int)(abs(textureOffSetY * texture_wheight / 40) % texture_width);

		*texelColor = wallTextures[6].textureBuffer[textureOffSetX +
				textureOffSetY * texture_width];
		drawPixel(*texelColor, p, y);
	}
}

/**
 * renderWall - renderWalls to our game
 *
 * Return: void
 */

void renderWall(void)
{
	int stripWallHeight, perpWallHeight, distanceFromTop, x, y, wallBottomPixel,
	    wallTopPixel, texture_width, texture_height, textureOffSetX, textureOffSetY;

	perpWallheight = rays[x].distance * cos(rays[x].rayan
