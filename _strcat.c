#include "shell.h"
/**
 * _strcat - s
 * @dest: s
 * @src: s
 * Return: s
 */
void _strcat(char *dest, const char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
}
