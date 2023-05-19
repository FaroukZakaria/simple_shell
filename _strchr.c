#include "shell.h"
/**
 * _strchr - s
 * @str: s
 * @n: s
 * Return: s
 */
char *_strchr(char *str, int n)
{
	while (*str != '\0')
	{
		if (*str == n)
		{
			return (str);
		}
		str++;
	}
	return (NULL);
}
