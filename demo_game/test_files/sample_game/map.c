#include "map.h"

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
    return map;
}

void free_map(int **map)
{
    int k;

    for (k = 0; k < ROWS; k++)
        free(map[k]);
    free(map);
}
