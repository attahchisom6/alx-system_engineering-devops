#include "game.h"

int main(void)
{
    if (!create_window_renderer())
    {
        fprintf(stderr, "Failed to execute the game.");
        return 1;
    }

    return 0;
}
