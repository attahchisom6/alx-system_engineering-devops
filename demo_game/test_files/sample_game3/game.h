#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include <SDL2/SDL.h>
#include "player.h"

bool initCamera(SDL_Event event, SDL_Renderer *renderer, Player *player); // Initialize camera based on user input
void raycasted(SDL_Renderer *renderer, Player *player);                   // Perform raycasting and draw walls
bool createWindowRenderer(void);                                          // Create window and renderer

#endif /* GAME_H */
