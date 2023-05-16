#include "shell.h"
/**
 * envp - makes envp that has all directories of PATH
 * Return: the envp
 */
char **envp()
{
	char *path = getenv("PATH");
	char **envp = NULL;
	char *env_path = NULL;
	int i, j, count;

	for (i = 0, count = 1; path[i]; i++)
	{
		if (path[i] == ':')
		{
			count++;
		}
	}
	envp = malloc((count + 1) * sizeof(char *));
	if (!envp)
	{
		perror("malloc failed");
		exit(1);
	}
	envp[0] = _strdup("PATH=");
	env_path = envp[0] + _strlen(envp[0]);
	for (i = 0, j = 0; path[i]; i++)
	{
		if (path[i] == ':')
		{
			env_path[j++] = '/';
			env_path[j] = '\0';
			envp[++count] = _strdup(envp[0]);
			env_path = envp[count] + _strlen(envp[count]);
			j = 0;
		}
		else
		{
			env_path[j++] = path[i];
			env_path[j] = '\0';
		}
	}
	env_path[j++] = '/';
	env_path[j] = '\0';
	envp[++count] = _strdup(envp[0]);
	envp[++count] = NULL;
	return envp;
}
