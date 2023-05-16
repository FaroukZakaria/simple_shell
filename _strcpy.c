#include "shell.h"
/**
 * _strcpy - s
 * @dest: s
 * @src: s
 * Return: s
 */
void _strcpy(char *dest, const char *src)
{
	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
}
