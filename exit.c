#include "shell.h"
/**
 * __exit - s
 * Return: s
 */
void __exit(void)
{
	if (_strcmp(av[0], "exit") == 0)
	{
		if (av[1] != NULL)
		{
			status = _atoi(av[1]);
			exit(status);
		}
		else
		{
			exit(0);
		}
	}
}
