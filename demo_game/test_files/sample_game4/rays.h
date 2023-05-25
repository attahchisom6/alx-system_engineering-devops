#ifndef RAYS_H
#define RAYS_H

/**
 * struct ray_s - struct store data of ray directions
 * @wallHitX: wall hit x coordinate
 * @wallHitY: wall hit y coordinate
 * @rayAngle: ray angle
 * @distanceToWall: distance to wall
 * @isVerticalHit: verify if the hit is vertical
 * @wallHitContent: wall hit content
 */

struct ray_s
{
	float wallHitX;
	float wallHitY;
	float rayAngle;
	float distanceToWall;
	bool isVerticalHit;
	int wallHitContent;
} ray_t;
