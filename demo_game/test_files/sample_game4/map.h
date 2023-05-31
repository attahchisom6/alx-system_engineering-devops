#ifndef MAP_H
#define MAP_H

#include "constants.h"

bool detectCollision(float x, float y);
bool isInsideMap(float x, float y);
int getMapContent(int row, int col);
void renderMap(void);

#endif /* MAP_H */
