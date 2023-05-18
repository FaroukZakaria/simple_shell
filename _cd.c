#include "shell.h"
/**
 * _cd - changes directory
 * Return: s
 */
void _cd(void)
{
	char *cwd = getcwd(NULL, 0);

	if (_strcmp(av[0], "cd") == 0 && av[1] != NULL)
	{
		chdir(av[1]);
		if (chdir(av[1]) != 0)
		{
			perror("cd");
			exit(1);
		}
		free(cwd);
	}
	else if (_strcmp(av[0], "cd") == 0 && av[1] == NULL)
	{
		chdir("/home");
	}
}
