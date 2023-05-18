#include "shell.h"
/**
 * __exit - s
 * Return: s
 */
int __exit(void)
{
	int stats;

	if (_strcmp(av[0], "exit") == 0)
	{
		if (av[1] != NULL)
		{
			stats = _atoi(av[1]);
			printf("status: %d\n", stats);
			exit(stats);
			return (stats);
		}
		else
		{
			exit(0);
			return (0);
		}
	}
	return (-1);
}
