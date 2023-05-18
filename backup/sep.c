#include "shell.h"
/**
 * sep - separates commands
 * Return: void
 */
void *sep(void)
{
	char comm[] = {NULL};
	int i, j = 0;

	for (i = 0; av[i] != NULL; i++)
	{
		if (_strcmp(av[i], ";") == 0)
		{

			execve(comm[0], comm, environ);
		}
		else
		{
			comm[j] = av[i];
			j++;
		}
	}
}
