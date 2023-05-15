#include "shell.h"
/**
 * error - handles the getline error
 * Return: void
 */
int error(void)
{
	if (getline(&line, &size, stdin) == -1)
	{
		printf("\n");
		return (-1);
	}
	return (0);
}
