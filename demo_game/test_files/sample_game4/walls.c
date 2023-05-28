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
 *
