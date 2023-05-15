#include "shell.h"
/**
 * shell_2 - handles arguments
 * Return: 0
 */
int shell_2(void)
{
	char *line = NULL;
	char *args[21];
	int i = 0;
	char *token;

	token = strtok(line, " ");
	i = 0;
	while (token)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	if (i > 0)
	{
		av[1] = args[1];
	}
	args[i] = NULL;
	return (0);
}
