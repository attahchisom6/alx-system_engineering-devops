#ifndef PLAYER_H
#define PLAYER_H

/**
 * Player - a structure containing information about the player
 * @x: X coordinate of the player
 * @y: y cordinate of the player
 * @width: player width
 * @height:player height
 * @turnDirection: turn direction
 * @walkDirection: walk direction
 * @rotationAngle: player rotation angle
 * @walkSpeed: walk speed
 * @turnSpeed: turn speed
 */

typedef struct Player_s {
    float x;
    float y;
    float width;
    float height;
    int turnDirection;
    float walkDirection;
    float rotationAngle;
    float rotationAngle; 
    float walkSpeed;
    float turnSpeed;
} Player_t;

extern Player_t player;

Player *createPlayer(float x, float y, float direction); // Create a new player
void destroyPlayer(Player_t *player);

#endif /* PLAYER_H */
