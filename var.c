#include "shell.h"
/**
 * _getenv - gets environment
 * @name: s
 * Return: s
 */
char *_getenv(const char *name)
{
	size_t n_ln = strlen(name);
	char *env;
	size_t env_len;
	int i = 0;

	if (name == NULL || environ == NULL)
		return (NULL);
	for (i = 0; environ[i] != NULL; i++)
	{
		env = environ[i];
		env_len = strlen(env);
		if (env_len >= n_ln && strncmp(env, name, n_ln) == 0 && env[n_ln] == '=')
			return (env + n_ln + 1);
	}
	return (NULL);
}
/**
 * _var - gets env variable
 * @envar: the variable string
 * Return: s
 */
char *_var(char *envar)
{
	return (_getenv(envar));
}
/**
 * ch_var - changes all the char * inside the char ** to their own variable
 * @envir: to be changed
 * Return: s
 */
char **ch_var(char **envir)
{
	int i = 0;

	for (i = 0; envir[i] != NULL; i++)
	{
		if (_var(envir[i]) != NULL)
		{
			_var(envir[i]);
		}
		else
		{
			continue;
		}
	}
	return (envir);
}
