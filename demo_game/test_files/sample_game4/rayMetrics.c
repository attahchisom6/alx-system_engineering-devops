#include "game.h"
#include <math.h>

/**
 * EuclideanDistance - get the pythogoreanean/Euclidean distance between two points
 * @x0: inital x coordinate
 * @y0: initial y coordinate
 * @x1: displaced x coordinate
 * @y1: displaced y coordinate
 *
 * Return: distance between two points in a grid
 */

float EuclideanDistance(float x0, float y0, float x1, float y1)
{
	float distance;

	distance = pow((x1 - x0), 2) + pow((y1 - y0), 2);
	distance = sqrt(distance);

	return (distance);
}

int main(void)
{
	printf("%f\n", EuclideanDistance(0, 5, 5, 0));
	return 0;
}
