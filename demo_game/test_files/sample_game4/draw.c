#include "game.h"

/**
 * drawRect - function to draw a Rectangle
 * @x: x cordinate
 * @y: y coordinate
 * @width: width of the rectangle
 * @height: height of the rectangle
 * @color: color of the line
 *
 * Return: void
 */

void drawRect(int x, int y, int width, int height, color_t color)
{
	int p, k;

	for (p = x; p < (x + width); p++)
		for (k = y; k < (y + height); k++)
			drawPixel(x, y, color);
}

/**
 * drawLine - function to draw a line
 * @x0: initialx coordinate of the point
 * @x1: a translational x coordinate of the point
 * @y0: initial y coordinate of the point
 * @y1: translated y coordinate of the point
 * @color: color of the lines
 *
 * Return: void
 */

void drawLine(int x0, int y0, int x1, int y1, color_t color)
{
	float currentX, currentY, Xincrement, Yincrement;
	int deltaX, deltaY, k, longestSide;

	deltaX = x1 - x0;
	deltaY = y1 - y0;
	longestSide = abs(deltaX) > abs(deltaY) ? abs(deltaX) : abs(deltaY);

	Xincrement = deltaX / (float)longestSide;
	Yincrement = deltaY / (float)longestSide;

	currentX = x0;
	currentY = y0;
	for (k = 0; k < longestSide; k++)
	{
		drawPixel(round(currentX), round(currentY), color);
		currentX += Xincrement;
		currentY += Yincrement;
	}
}
