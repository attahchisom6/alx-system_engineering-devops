#include "player.h"
#include <stdlib.h>

Player *createPlayer(float x, float y, float direction)
{
    Player *player = malloc(sizeof(Player));
    if (player == NULL) {
        return NULL;
    }

    player->x = x;
    player->y = y;
    player->direction = direction;

    return player;
}

void destroyPlayer(Player *player)
{
    if (player != NULL) {
        free(player);
    }
}
