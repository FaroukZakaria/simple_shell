#include "shell.h"
/**
 * _bin - s
 * @str: s
 * Return: s
 */
char *_bin(char *str)
{
	char *prefix = "/bin/";
	int str_len = _strlen(str);
	int prefix_len = _strlen(prefix);
	char *new_str = (char *) malloc(str_len + prefix_len + 1);

	if (_strncmp(str, prefix, _strlen(prefix)) != 0)
	{
		_strcpy(new_str, prefix);
		_strcat(new_str, str);
		return (new_str);
	}
	else
	{
		return (str);
	}
}
