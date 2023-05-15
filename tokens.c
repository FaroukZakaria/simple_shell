#include "shell.h"
/**
 * token - accepts arguments
 * Return: arguments
 */
void token(void)
{
	int i = 0;
	char *token = strtok(line, " ");

	while (token)
	{
		av[i++] = token;
		token = strtok(NULL, " ");
	}
	av[i] = NULL;
}
