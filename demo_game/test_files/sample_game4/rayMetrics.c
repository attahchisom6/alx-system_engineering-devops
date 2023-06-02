#include "game.h"

/**
 * EuclideanDistance - get the pythogoreanean/Euclidean distance
 * between two points
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

/**
 * isRayFacingDown - checks if the rays is facing down
 * @rayAngle: ray Angle
 *
 * Return: true if ray is facing down else false
 */

bool isRayFacingDown(float rayAngle)
{
	if (rayAngle > 0 && rayAngle < PI)
		return (true);
	return (false);
}

/**
 * isRayFacingUp - check if the ray is facing up
 * @rayAngle: ray Angle
 *
 * Return: true ic ray is facing up else false
 */

bool isRayFacingUp(float rayAngle)
{
	return (!isRayFacingDown(rayAngle));
}

/**
 * isRayFacingRight - checks if the ray is facing right
 * @rayAngle: rayAngle
 *
 * Return: true if ray is facing right, else false
 */

bool isRayFacingRight(float rayAngle)
{
	if (rayAngle < (PI / 2) || rayAngle > TWO_PI / 3)
		return (true);
	return (false);
}

/**
 * isRayFacingLeft - checks if the ray os facing left
 * @rayAngle: angle of the ray
 *
 * Return: true if ray is facing left
 */

bool isRayFacingLeft(float rayAngle)
{
	return (!isRayFacingRight(rayAngle));
}
