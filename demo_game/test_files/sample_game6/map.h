#ifndef MAP_H
#define MAP_H

#define ROWS 9
#define COLUMNS 10
#define titleSize 64

int **renderMap(void);
void freeMap(int **map);

#endif /* MAP_H */
