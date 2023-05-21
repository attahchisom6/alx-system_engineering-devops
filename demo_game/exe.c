#include "MyHeaders/sources.h"

/**
 * main - driver programm to execute our files
 *
 * Return: 0 on success
 */

int main(void)
{
	if (!create_window_renderer())
	{
		fprintf(stderr, "can't execute");
		return (1);
	}
	return (0);
}
