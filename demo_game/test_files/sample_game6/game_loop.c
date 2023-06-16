#include "game.h"

int main(void)
{
    bool isRunning = true;

    if (!createWindowRenderer())
    {
        isRunning = false;
    }

    while (isRunning)
    {
        clearColorBuffer(0xFF000000);

        // Update game state and handle input

        // Render the walls
        renderWall();

        // Render the color buffer to the screen
        renderColorBuffer();

        // Process events
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                isRunning = false;
            }
        }
    }

    // destroyWindowRenderer();

    return 0;
}
hello
