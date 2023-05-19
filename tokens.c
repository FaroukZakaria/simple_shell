#include "shell.h"
/**
 * token - accepts arguments
 * Return: arguments
 */
void token(void)
{
	int i = 0;
	char *token = _strtok(line, " ");

	while (token)
	{
		av[i++] = token;
		token = _strtok(NULL, " ");
	}
	av[i] = NULL;
}
