#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include <SDL2/SDL.h>

bool initCamera(SDL_Event event, SDL_Renderer *renderer);
void raycasted(SDL_Renderer *renderer);
void gameLoop(void);
bool createWindowRenderer(void);

#endif /* GAME_H */
