#include "game.h"

ray_t rays[NUM_RAYS];
Player_t player;

static bool foundHorzWallHit, foundVertWallHit;
static float horzWallHitX, horzWallHitY, horzWallContent;
static float vertWallHitX, vertWallHitY, vertWallContent;
/**
 * HorzIntersection - find horizontal intersection on a wall
 * @rayAngle: current ray angle
 *
 * Return: void
 */

void HorzIntercept(float rayAngle)
{
	float Ystep, Xstep, Yintercept, Xintercept, nextHorzHitX, nextHorzHitY;

	foundHorzWallHit = false;
	horzWallHitX = horzWallHitY = horzWallContent = 0;

	Yintercept = floor(player.y / titleSize) * titleSize;
	Yintercept += isRayFacingDown(rayAngle) ? titleSize : 0;
	Xintercept = player.x + (player.y - Yintercept) / tan(rayAngle);

	Ystep = titleSize;
	Ystep *= isRayFacingUp(rayAngle) ? -1 : 1;
	Xstep = titleSize / tan(rayAngle);
	Xstep *= isRayFacingLeft(rayAngle) && rayAngle > 0 ? -1: 1;
	Xstep *= isRayFacingRight(rayAngle) && rayAngle < 0 ? -1 : 1;

	nextHorzHitX = Xintercept;
	nextHorzHitY = Yintercept;

	while (isInsideMap(nextHorzHitX, nextHorzHitY))
	{
		float testXintercept = nextHorzHitY;
		float testYintercept = nextHorzHitY + isRayFacingUp(rayAngle) ? -1 : 0;

		if (detectCollision(testXintercept, testYintercept))
		{
			horzWallHitX = nextHorzHitX;
			horzWallHitY = 	nextHorzHitY + isRayFacingUp(rayAngle);
			horzWallContent = getMapContent((int)floor(testXintercept / titleSize),
					(int)floor(testYintercept / titleSize));

			foundHorzWallHit = true;
			break;
		}

		nextHorzHitX = Xstep;
		nextHorzHitY = Ystep;
	}
}

/**
 * VertIntercept - checks and calculates for vartical interception
 *
 * Return: void
 */

void VertIntercept(float rayAngle)
{
	float Xstep, Ystep, Xintercept, Yintercept, nextVertHitX, nextVertHitY;

	foundVertWallHit = false;
	vertWallHitX = vertWallHitY = vertWallContent = 0;

	Xintercept = floor(player.x * titleSize) / titleSize;
	Xintercept += isRayFacingRight(rayAngle) ? titleSize : 0;
	Yintercept = player.y + (Xintercept - player.x) * tan(rayAngle);

	Xstep = titleSize;
	Xstep *= isRayFacingLeft(rayAngle) ? -1 : 1;
	Ystep = titleSize * tan(rayAngle);
	Ystep *= isRayFacingUp(rayAngle) && Ystep > 0 ? -1 : 1;
	Ystep *= isRayFacingDown(rayAngle) && Ystep < 0 ? -1 : 1;

	nextVertHitX = Xintercept;
	nextVertHitY = Yintercept;

	while (isInsideMap(nextVertHitX, nextVertHitY))
	{
		float testXintercept = nextVertHitX + isRayFacingLeft(rayAngle) ? -1 : 0; 
		float testYintercept = nextVertHitY;

		if (detectCollision(testXintercept, testYintercept))
		{
			vertWallHitX = nextVertHitX;
			vertWallHitY = nextVertHitY;
			vertWallContent = getMapContent((int)floor(testXintercept / titleSize),
					(int)floor(testYintercept / titleSize));

			foundVertWallHit = true;
			break;
		}
		nextVertHitX += Xstep;
		nextVertHitY += Ystep;
	}
}

/**
 * cast_ray - casts a single ray to the projection plane
 * @rayAngle: angle of the ray
 * @rayId: ray identifier
 *
 * Return: void
 */

void cast_ray(float rayAngle, int rayId)
{
	float horzDistanceHit = 0, vertDistanceHit = 0;

	rayAngle = remainder(rayAngle, TWO_PI);
	if (rayAngle < 0)
		rayAngle = rayAngle + TWO_PI;
	HorzIntercept(rayAngle);
	VertIntercept(rayAngle);

	horzDistanceHit = foundHorzWallHit ? EuclideanDistance(player.x, horzWallHitX,
			player.y, horzWallHitY) : FLT_MAX;
	vertDistanceHit = foundVertWallHit ? EuclideanDistance(player.x, vertWallHitX, player.y, vertWallHitY) : FLT_MAX;

	if (horzDistanceHit < vertDistanceHit)
	{
		rays[rayId].wallHitX = horzWallHitX;
		rays[rayId].wallHitY = horzWallHitY;
		rays[rayId].rayAngle = rayAngle;
		rays[rayId].distanceToWall = horzDistanceHit;
		rays[rayId].isVerticalHit = false;
		rays[rayId].wallHitContent = horzWallContent;
	}
	else
	{
		rays[rayId].wallHitX = vertWallHitX;
		rays[rayId].wallHitY = vertWallHitY;
		rays[rayId].rayAngle = rayAngle;
		rays[rayId].distanceToWall = vertDistanceHit;
		rays[rayId].isVerticalHit = true;
		rays[rayId].wallHitContent = vertWallContent;
	}
}

/**
 * cast_all_rays - cat all rays to the window
 * rayAngle: angle of the ray casted to the wall
 *
 * Return: void
 */

void cast_all_rays(void)
{
	int col;

	for (col = 0; col < NUM_RAYS; col++)
	{
		float rayAngle = player.rotationAngle + atan((col - NUM_RAYS / 2) / PROJ_PLANE);
		cast_ray(rayAngle, col);
	}
}

/**
 * renderRays - draws all rays accordingly into the projection plane
 *
 * Return: void
 */

void renderRays(void)
{
	int k;

	for (k = 0; k < NUM_RAYS; k += 48)
	{
		drawLine(
			player.x * SCALE_FACTOR,
			player.y * SCALE_FACTOR,
			rays[k].wallHitX * SCALE_FACTOR,
			rays[k].wallHitY * SCALE_FACTOR,
			0xFF0000FF
			);
	}
}
