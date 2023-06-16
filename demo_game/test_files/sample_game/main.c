#include "game.h"

int main(void)
{
	SDL_Renderer *renderer;
    if (!create_window_renderer(renderer))
    {
        fprintf(stderr, "Failed to execute the game.");
        return 1;
    }

    return 0;
}
