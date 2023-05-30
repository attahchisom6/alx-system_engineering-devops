#include "game.h"

ray_t rays[NUM_RAYS];
texture_t wallTextures[NUM_TEXTURES];
Player_t player;

void changeColorIntensity(color_t *color, float factor)
{
    color_t alpha = (*color & 0xFF000000);
    color_t red = (*color & 0x00FF0000) * factor;
    color_t green = (*color & 0x0000FF00) * factor;
    color_t blue = (*color & 0x000000FF) * factor;

    *color = alpha | (red & 0x00FF0000) | (green & 0x0000FF00) | (blue & 0x000000FF);
}

void renderFloor(int wallBottomPixel, color_t *texelColor, int p)
{
    int y, texture_height, texture_width, textureOffSetX, textureOffSetY;
    float distance, ratio;

    texture_width = wallTextures[3].width;
    texture_height = wallTextures[3].height;

    for (y = wallBottomPixel - 1; y < SCREEN_HEIGHT; y++)
    {
        ratio = player.height / (y - SCREEN_HEIGHT / 2);
        distance = (ratio * PROJ_PLANE) / cos(rays[p].rayAngle - player.rotationAngle);

        textureOffSetX = (int)(abs(player.x + distance * cos(rays[p].rayAngle)));
        textureOffSetY = (int)(abs(player.y + distance * sin(rays[p].rayAngle)));

        textureOffSetX = (int)(abs(textureOffSetX * texture_width / 30) % texture_width);
        textureOffSetY = (int)(abs(textureOffSetY * texture_height / 30) % texture_height);

        *texelColor = wallTextures[4].textureBuffer[textureOffSetX + textureOffSetY * texture_width];
        drawPixel(p, y, *texelColor);
    }
}

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

        textureOffSetX = (int)(abs(textureOffSetX * texture_width / 40) % texture_width);
        textureOffSetY = (int)(abs(textureOffSetY * texture_height / 40) % texture_width);

        *texelColor = wallTextures[6].textureBuffer[textureOffSetX + textureOffSetY * texture_width];
        drawPixel(p, y, *texelColor);
    }
}

void renderWall(void)
{
    int stripWallHeight, distanceFromTop, x, y, wallBottomPixel, textNum,
        wallTopPixel, texture_width, texture_height, textureOffSetX,
        textureOffSetY;

    float perpDistance, projectedWallHeight;
    color_t texelColor;

    for (x = 0; x < NUM_RAYS; x++)
    {
        perpDistance = rays[x].distanceToWall * cos(rays[x].rayAngle - player.rotationAngle);
        projectedWallHeight = (titleSize / perpDistance) * PROJ_PLANE;

        stripWallHeight = (int)projectedWallHeight;
        wallTopPixel = (SCREEN_HEIGHT / 2) - (stripWallHeight / 2);
        wallBottomPixel = (SCREEN_HEIGHT / 2) + (stripWallHeight / 2);
        distanceFromTop = wallTopPixel + 1;

        textNum = rays[x].isVerticalHit ? 1 : 0;
        texture_width = wallTextures[textNum].width;
        texture_height = wallTextures[textNum].height;

        textureOffSetX = (int)(rays[x].wallHitX * texture_width) % texture_width;

        if (rays[x].isVerticalHit)
            textureOffSetX = (int)(rays[x].wallHitY * texture_width) % texture_width;

        for (y = distanceFromTop; y < wallBottomPixel; y++)
        {
            textureOffSetY = (y * 2 - SCREEN_HEIGHT + stripWallHeight) * (texture_height / 2) / stripWallHeight;
            texelColor = wallTextures[textNum].textureBuffer[textureOffSetX + textureOffSetY * texture_width];
            drawPixel(x, y, texelColor);
        }

        renderFloor(wallBottomPixel, &texelColor, x);
        renderCeiling(wallTopPixel, &texelColor, x);
    }
}
