#include "game.h"

/**
 * main - driver program to run our code
 *
 * Return: 0 on success
 */

int main(void)
{
    if (!createWindowRenderer())
    {
        fprintf(stderr, "Failed to execute the game.");
        return 1;
    }

    return 0;
}
