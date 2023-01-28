/*
 * File: 102-zombie.c
 * Auth: Brennan D Baraban
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * infinite_while - Run an infinite while loop.
 *
 * Return: Always 0.
 */
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main - Creates five zombie processes.
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t pid;
	int k = 0;

	while (k < 5)
	{
		pid = fork();
		if (pid > 0)
			fprintf(stdout, "Zombie process created, PID: %d\n", pid);
		else
			exit(0);
		k++;
	}
	infinite_while();
	return (EXIT_SUCCESS);
}
