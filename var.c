#include "shell.h"
/**
 * _getenv - gets environment
 * @name: s
 * Return: s
 */
char *_getenv(const char *name)
{
	size_t n_ln = _strlen(name);
	char *env;
	size_t env_len;
	int i = 0;

	if (name == NULL || environ == NULL)
		return (NULL);
	for (i = 0; environ[i] != NULL; i++)
	{
		env = environ[i];
		env_len = _strlen(env);
		if (env_len >= n_ln && _strncmp(env, name, n_ln) == 0 && env[n_ln] == '=')
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
 * _btoi - turns int to string
 * @value: value
 * Return: s
 */
char *_btoi(int value)
{
	int temp = value, len = 1, index = len - 1;
	char *result = (char *)malloc((len + 1) * sizeof(char));

	if (result == NULL)
		return (NULL);
	while (temp /= 10)
		len++;
	while (value)
	{
		result[index--] = '0' + (value % 10);
		value /= 10;
	}
	result[len] = '\0';
	return (result);
}
/**
 * _pid_get - gets pid in form of char **
 * @envir: the value
 * Return: s
 */
int _pid_get(char **envir)
{
	int i = 1;

	for (i = 1; envir[i] != NULL; i++)
	{
		if (envir[i][0] == '$')
		{
			if (envir[i][1] == '$')
			{
				envir[i] = _btoi(getpid());
			}
		}
	}
	return (-1);
}
/**
 * ch_var - changes all the char * inside the char ** to their own variable
 * @envir: to be changed
 * Return: s
 */
char **ch_var(char **envir)
{
	int i = 0;
	char *value;

	for (i = 0; envir[i] != NULL; i++)
	{
		if (envir[i][0] == '$')
		{
			value = _var((envir[i]) + 1);
			if (value != NULL)
			{
				envir[i] = value;
			}
		}
		else
		{
			continue;
		}
	}
	return (envir);
}
