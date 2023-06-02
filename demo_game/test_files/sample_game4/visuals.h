#ifndef VISUALS_H
#define VISUALS_H

#include "constants.h"

typedef uint32_t color_t;

/**
 * struct texture_s - renders the texture of a surface to a window
 * @width: width of the texture
 * @height: height of the texture
 * @textureBuffer: pointer to texture buffer
 * @upngTexture: pointer to upng texture
 *
 * description: handles dcreen texture
 */

typedef struct texture_s
{
	int width;
	int height;
	color_t *textureBuffer;
	/*upng_t *upngTexture;*/
} texture_t;

extern texture_t wallTextures[NUM_TEXTURES];

/* visual functions */
bool createWindowRenderer(void);
void close(void);
void clearColorBuffer(color_t color);
void renderColorBuffer(void);
void drawPixel(int x, int y, color_t color);

/*wall, floor and ceiling functions*/
void changeColorItensity(color_t *color, float factor);
void renderFloor(int BottomTopPixel, color_t *texelColor, int p);
void renderCeiling(int wallTopPixel, color_t *texelColor, int p);
void renderWall(void);

/*draw functions */
void drawRect(int x, int y, int width, int height, color_t color);
void drawLine(int x0, int y0, int x1, int y1, color_t color);

#endif
