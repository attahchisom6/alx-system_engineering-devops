#include "game.h"

ray_t rays[NUM_RAYS];

static bool foundHorzWallHit, foundVertWallHit;
static float horzWallHitX, horzWallHitY, HorzWallContent, vertWallHitX, vertWallHitY;
/**
 * HorzIntersection - find horizontal intersection on a wall
 * @rayAngle: current ray angle
 *
 * Return: void
 */

void HorzIntersection(float rayAngle)
{
	float Ystep, Xstep, Yintercept, Xintercept, nextHorzHitX, nextHorzHitY;

	foundHorzWallhit = false;
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
