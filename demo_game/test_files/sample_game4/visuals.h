#ifndef VISUALS_H
#define VISUALS_H

#define NUM TEXTURES 8

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
	upng_t *upngTexture;
} texture_t;

textture_t wallTexture[NUM_TEXTURES];
