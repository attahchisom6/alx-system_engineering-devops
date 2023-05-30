#include "game.h"

ray_t rays[NUM_RAYS];
texture_t wallTextures[NUM_TEXTURES];
Player_t player;

/**
 * changeColorIntensity - function to unmask a color bit
 * and itensify it based on the intesity factor, it does
 * this by masking(hide because bit manipulation by 0 return 0) out
 * all undesired colors,
 * then isolate the desired color and itensify it
 * @color: color itensity to change
 * @factor: itensity factor
 *
 * Return: void
 */

void changeColorIntensity(color_t *color, float factor)
{
	color_t alpha  = (*color & 0xFF000000);
	color_t red = (*color & 0x00FF0000) * factor;
	color_t green = (*color & 0x0000FF00) * factor;
	color_t blue = (*color & 0x000000FF) * factor;

	*color = alpha | (red & 0x00FF0000) | (green & 0x0000FF00)
		| (blue & 0x000000FF);
}

/**
 * renderFloor - render floor projection
 * @wallBottomPixel: The bottom pixel of the wall
 * @texelColor: texture color
 * @p: current element in the ray arraya
 *
 * Return: void
 */

void renderFloor(int wallBottomPixel, color_t *texelColor, int p)
{
	int y, texture_height, texture_width, textureOffSetX, textureOffSetY;
	float distance, ratio;

	texture_width = wallTextures[3].width;
	texture_height = wallTextures[3].height;

	for (y = wallBottomPixel - 1; y < SCREEN_HEIGHT; y++)
	{
		ratio = player.height / (y - SCREEN_HEIGHT / 2);
		distance = (ratio * PROJ_PLANE) / cos(rays[p].rayAngle -
				player.rotationAngle);

		textureOffSetX = (int)(abs(player.x + distance * cos(rays[p].rayAngle)));
		 textureOffSetY = (int)(abs(player.y + distance * sin(rays[p].rayAngle)));

		textureOffSetX = (int)(abs(textureOffSetX * texture_width / 30) %
				texture_width);
		textureOffSetY = (int)(abs(textureOffSetY * texture_height / 30) %
				texture_height);

		*texelColor = wallTextures[4].
			textureBuffer[textureOffSetX + textureOffSetY * texture_width];
		drawPixel(*texelColor, p, y);
	}
}

/**
 * renderCeiling - render the ceiling
 * @wallTopTexture: texture of the ceiling
 * @texelColor: texture color
 * @p:current element in the ray array
 *
 * Return: void
 */

void renderCeiling(int wallTopPixel, color_t *texelColor, int p)
{
	int y, texture_height, texture_width, textureOffSetX, textureOffSetY;
	float distance, ratio;

	texture_width = wallTextures[3].width;
	texture_height = wallTextures[3].height;

	for (y = 0; y < wallTopPixel; y++)
	{
		ratio = player.height / (y - SCREEN_HEIGHT / 2);
		distance = ratio * PROJ_PLANE / cos(rays[p].rayAngle - player.rotationAngle);

		textureOffSetX = (int)(abs(player.x - distance * cos(rays[p].rayAngle)));
		textureOffSetY = (int)(abs(player.y - distance * sin(rays[p].rayAngle)));

		textureOffSetX = (int)(abs(textureOffSetX * texture_width / 40) %
				texture_width);
		textureOffSetY = (int)(abs(textureOffSetY * texture_height / 40) %
				texture_width);

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
	int stripWallHeight, distanceFromTop, x, y, wallBottomPixel, textNum,
	    wallTopPixel, texture_width, texture_height, textureOffSetX,
	    textureOffSetY;

	float perpDistance, projectedWallHeight;
	color_t texelColor;

	for (x = 0; x < NUM_RAYS; x++)
	{
		perpDistance = rays[x].distanceToWall * cos(rays[x].rayAngle);
		projectedWallHeight = (PROJ_PLANE * titleSize) / perpDistance;
		stripWallHeight = (int)(projectedWallHeight);
		wallBottomPixel = (stripWallHeight / 2) - (SCREEN_HEIGHT / 2);
		wallBottomPixel = wallBottomPixel < 0 ? 0 : wallBottomPixel;
		wallTopPixel = (stripWallHeight / 2) + (SCREEN_HEIGHT / 2);
		wallTopPixel = wallTopPixel > SCREEN_HEIGHT ? SCREEN_HEIGHT : wallTopPixel;
		textNum =  rays[x].wallHitContent - 1;
		texture_width = wallTextures[3].width;
		texture_height = wallTextures[3].height;
		renderFloor(wallBottomPixel, &texelColor, x);
		renderCeiling(wallTopPixel, &texelColor, x);

		if (rays[x].isVerticalHit)
			textureOffSetX = (int)rays[x].wallHitX % titleSize;
		else
			textureOffSetY = (int)rays[x].wallHitX % titleSize;

		for (y = wallTopPixel; y < wallBottomPixel; y++)
		{
			distanceFromTop = y + (stripWallHeight / 2) - (SCREEN_HEIGHT / 2);
			textureOffSetY = distanceFromTop * ((float)texture_height / stripWallHeight);
			texelColor = wallTextures[6].
				textureBuffer[textureOffSetX + textureOffSetY * texture_width];

			if (rays[x].isVerticalHit)
				changeColorIntensity(&texelColor, 0.5);
			drawPixel(x, y, texelColor);
		}
	}
}
