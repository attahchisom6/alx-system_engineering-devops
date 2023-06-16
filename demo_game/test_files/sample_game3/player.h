#ifndef PLAYER_H
#define PLAYER_H

typedef struct Player {
    float x;             // X-coordinate of the player
    float y;             // Y-coordinate of the player
    float direction;     // Direction of the player (in radians)
} Player;

Player *createPlayer(float x, float y, float direction); // Create a new player
void destroyPlayer(Player *player);                      // Destroy the player

#endif /* PLAYER_H */
