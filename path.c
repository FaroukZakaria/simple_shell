#include "shell.h"
/**
 * path - s
 * Return: s
 */
char **path(void)
{
	char *path = _getenv("PATH");
	char *path_dirs[256];
	int i = 0;
	char *dir = strtok(path, ":");
	char **path_dirs_copy = malloc(sizeof(path_dirs));

	while (dir != NULL)
	{
		path_dirs[i++] = dir;
		dir = strtok(NULL, ":");
	}
	path_dirs[i] = NULL;
	_memcpy(path_dirs_copy, path_dirs, sizeof(path_dirs));
	return (path_dirs_copy);
}
