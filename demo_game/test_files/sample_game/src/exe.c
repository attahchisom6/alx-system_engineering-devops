#include "game.h"

int main(void)
{
    Game game;

    if (!game_init(&game))
    {
        fprintf(stderr, "Failed to initialize the game.\n");
        return 1;
    }

    if (!game_create_window_renderer(&game))
    {
        fprintf(stderr, "Failed to create window and renderer.\n");
        game_cleanup(&game);
        return (1);
    }

    game_run(&game);
    game_cleanup(&game);

    return (0);
}
