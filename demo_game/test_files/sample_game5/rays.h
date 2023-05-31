#ifndef RAYS_H
#define RAYS_H

#define NUM_RAYS SCREEN_WIDTH

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
void HorzIntersection(float rayAngle);
void VertIntersection(float rayAngle);
void cast_ray(float rayAngle, int rayId);
void cast_all_rays(void);
void renderRays(void);

#endif /* RAYS_H */
