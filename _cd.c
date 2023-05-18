#include "shell.h"
/**
 * _cd - changes directory
 * Return: s
 */
char *_cd(void)
{
	if (_strcmp(av[0], "cd") == 0 && av[1] != NULL)
	{
		if (_strcmp(av[0], "cd") == 0 && _strcmp(av[1], "-") == 0)
		{
			return ("/home");
		}
		if (_strcmp(av[0], "cd") == 0 && av[1] != NULL && av[2] != NULL)
		{
			perror("cd: too many arguments");
		}
		return (av[1]);
	}
	else if (_strcmp(av[0], "cd") == 0 && av[1] == NULL)
	{
		return ("/home");
	}
	return ("/home");
}
