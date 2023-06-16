#include <stdio.h>
#include "game.h"

int main(void)
{
    if (!createWindowRenderer()) {
        fprintf(stderr, "Failed to create window and renderer.\n");
        return 1;
    }

    return 0;
}
