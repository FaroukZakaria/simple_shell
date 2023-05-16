#include "shell.h"
/**
 * _strdup - duplicate
 * @str: s
 * Return: dup
 */
char *_strdup(const char *str)
{
	size_t len = strlen(str) + 1;
	char *new_str = malloc(len);

	if (new_str == NULL)
	{
		return (NULL);
	}
	_memcpy(new_str, str, len);
	return (new_str);
}
