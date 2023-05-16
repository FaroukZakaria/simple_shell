#include "shell.h"
/**
 * _getenv - get environment
 * @name: s
 * Return: s
 */
char *_getenv(const char *name)
{
	extern char **environ;
	int len = _strlen(name);
	char **env;

	for (env = environ; *env != NULL; ++env)
	{
		if (_strncmp(name, *env, len) == 0 && (*env)[len] == '=')
		{
			return (*env + len + 1);
		}
	}
	return (NULL);
}
