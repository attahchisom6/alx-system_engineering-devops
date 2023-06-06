#include <stdio.h>
#include <stdlib.h>

#define COLS 5
#define ROWS 9

int main(void)
{
	int k, p;
	char *map = malloc(ROWS * COLS * sizeof(char));
	for (p = 0; p < ROWS; p++)
	{
		for (k = 0; k < COLS; k++)
		{
			map[p + k * COLS] = 5;
		}
	}

	for (p = 0; p < ROWS; p++)
	{
		for (k = 0; k < COLS; k++)
		{
			printf("%d ", map[p + k * COLS]);
		}
		printf("\n");
	}
	free(map); // ok
}
