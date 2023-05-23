#ifndef RAYCASTED_GAME_H
#define RAYCASTED_GAME_H

#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 320
#define PI 3.1415926535897

bool create_window_renderer(void);
void close(SDL_Window *window, SDL_Renderer *renderer);
void game_loop(void);
bool Init_camera(SDL_Event event);

#endif
