#ifndef RAYS_H
#define RAYS_H

#include "constants.h"

/**
 * struct ray_s - struct store data of ray directions
 * @wallHitX: wall hit x coordinate
 * @wallHitY: wall hit y coordinate
 * @rayAngle: ray angle
 * @distanceToWall: distance to wall
 * @isVerticalHit: verify if the hit is vertical
 * @wallHitContent: wall hit content
 */

typedef struct ray_s
{
	float wallHitX;
	float wallHitY;
	float rayAngle;
	float distanceToWall;
	bool isVerticalHit;
	int wallHitContent;
} ray_t;

extern ray_t rays[NUM_RAYS];

/*ray function*/
void HorzIntercept(float rayAngle);
void VertIntercept(float rayAngle);
void cast_ray(float rayAngle, int rayId);
void cast_all_rays(void);
void renderRays(void);

/*rayMetric functions*/
float EuclideanDistance(float, float, float, float);
bool isRayFacingDown(float);
bool isRayFacingUp(float);
bool isRayFacingRight(float);
bool isRayFacingLeft(float);

#endif /* RAYS_H */