#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include <SDL2/SDL.h>
#include "player.h"
#include "map.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define SCREEN_WIDTH 680
#define SCREEN_HEIGHT 420
#define PI 3.141592

bool initCamera(SDL_Event event, SDL_Renderer *renderer, Player *player); // Initialize camera based on user input
void raycasted(SDL_Renderer *renderer, Player *player);                   // Perform raycasting and draw walls
bool createWindowRenderer(void);                                          // Create window and renderer
void close(SDL_Window *window, SDL_Renderer *renderer, Player *player);

#endif /* GAME_H */
