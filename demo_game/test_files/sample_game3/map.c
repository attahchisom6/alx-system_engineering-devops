#include "game.h"

/**
 * This function servers to render the way our game world is. it defines the structure
 * of its walls and pillars
 * @map: a double pointer to hold the grid of arrays
 *
 * Return: a pointer to a pointer to the grid array
 */

int **renderMap(void)
{
    int **map = malloc(ROWS * sizeof(int *));
    int k, p;

    for (k = 0; k < ROWS; k++)
    {
        map[k] = malloc(COLUMNS * sizeof(int));
    }

    int InitialMap[ROWS][COLUMNS] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    for (p = 0; p < ROWS; p++)
    {
        for (k = 0; k < COLUMNS; k++)
        {
            map[p][k] = InitialMap[p][k];
        }
    }
    return (map);
}

/**
 * free_map - frees memory allocated to our world
 * @map: a double pointer to our game world
 *
 * Return: void
 */

void freeMap(int **map)
{
    int k;

    for (k = 0; k < ROWS; k++)
        free(map[k]);
    free(map);
}
