#ifndef VISUALS_H
#define VISUALS_H

#define NUM_TEXTURES 8

/**
 * struct texture_s - renders the texture of a surface to a window
 * @width: width of the texture
 * @height: height of the texture
 * @textureBuffer - pointer to texture buffer
 * @upngTexture: pointer to upng texture
 *
 * description: handles dcreen texture
 */

typedef uint64_t color_t;

typedef struct texture_s
{
	int width;
	int height;
	color_t *textureBuffer;
	/*upng_t *upngTexture;*/
} texture_t;

extern texture_t wallTexture[NUM_TEXTURES];

/* visual functions */
bool createWindowRenderer(void);
void close(void);
void clearColorBuffer(color_t color);
void renderColorBuffer(void);
void drawPixel(color_t color, int x, int y);

/*wall, floor and ceiling functions*/
void changeColorItensity(color_t *color, float factor);
void renderFloor(int BottomTopPixel, color_t *texelColor, int p);
void renderCeiling(int wallTopPixel, color_t *texelColor, int p);
void renderWall(void);
#endif
