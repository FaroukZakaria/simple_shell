#include "shell.h"

/**
 * _strlen - get length of string input
 * Return: length
 */
size_t _strlen(const char *str)
{
	size_t len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}
