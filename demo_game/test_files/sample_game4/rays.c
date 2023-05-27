#include "game.h"

ray_t rays[NUM_RAYS];

static bool foundHorzWallHit = false, foundVertWallHit = false;
static float horzWallHitX, horzWallHitY, HorzWallContent;
static float vertWallHitX, vertWallHitY, vertWallContent;
/**
 * HorzIntersection - find horizontal intersection on a wall
 * @rayAngle: current ray angle
 *
 * Return: void
 */

void HorzIntersection(float rayAngle)
{
	float Ystep, Xstep, Yintercept, Xintercept, nextHorzHitX, nextHorzHitY;

	foundHorzWallHit = false;
	HorzWallHitX = HorzWallHitY = HorzWallContent = 0;

	Yintercept = floor(player.y / titleSize) * titleSize;
	Yintercept += isRayFacingDown(rayAngle) ? titleSize : 0;
	Xintercept = player.x + (y.player - Yintercept) / tan(rayAngle);

	Ystep = titleSize;
	Ystep *= isRayFacingUp(rayAngle) ? -1 : 1;
	Xstep = titleSize / tan(rayAngle);
	Xstep *= isRayFacingLeft(rayAngle) && rayAngle > 0 ? -1: 1;
	Xstep *= isRayFacingRight(rayAngle) && rayAngle < 0 ? -1 : 1;

	nextHorzHitX = Xintercept;
	nextHorzHitY = Yintercept;

	while (isInsideMap(nextHorzHitX, nextHorzHitY))
	{
		float Ytest = nextHorzHitY, Xtest = nextHorzHitY;
+

		if (detectCollision(Xtest, Ytest))
		{
			horzWallHitX = nextHorzHitX;
			horzWallHitY = 	nextHorzHitY + isRayFacingUp(rayAngle);
			horzWallContent = getMapContent((int)floor(Xtest / titleSize),
					(int)floor(Ytest / titleSize));

			foundHorzWallHit = true;
			break;
		}

		nextHorzWallHitX = Xstep;
		nextHorzWallHitY = Ystep;
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

	vertHitWallX = vertHitWallY = vertWallContent = 0;

	Xintercept = floor(player.x * titleSize) / titleSize
	Xintercept += isRayFacingRight(rayAngle) ? titleSizei : 0;
	Yintercept = player.y + (Xintercept - player.x) * tan(rayAngle);

	Xstep = titleSIze;
	Xstep *= isRayFacingLeft(rayAngle) ? -1 : 1;
	Ystep = 
