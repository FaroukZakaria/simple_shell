#include "shell.h"
/**
 * handle - handle path
 * Return: s
 */
void handle(void)
{
	int path_c = 0;
	char *path = getenv("PATH");
	char *path_token = strtok(path, ":");
	char *paths[64];

	while (path_token != NULL)
	{
		paths[path_c++] = path_token;
		path_token = strtok(NULL, ":");
	}
}
