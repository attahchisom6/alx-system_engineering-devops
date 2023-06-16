#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

bool create_window_renderer(SDL_Renderer *renderer);
void game_loop(void);
void free_map(int **map);

#endif /* GAME_H */
