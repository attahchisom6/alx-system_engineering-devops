#include <stdlib.h>
#include "map.h"

int** renderMap()
{
    int** map = malloc(ROWS * sizeof(int*));
    for (int i = 0; i < ROWS; i++) {
        map[i] = malloc(COLUMNS * sizeof(int));
        for (int j = 0; j < COLUMNS; j++) {
            map[i][j] = 0;
        }
    }

    int initialMap[ROWS][COLUMNS] = {
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

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            map[i][j] = initialMap[i][j];
        }
    }

    return map;
}

void freeMap(int **map)
{
    for (int i = 0; i < ROWS; i++) {
        free(map[i]);
    }
    free(map);
}
