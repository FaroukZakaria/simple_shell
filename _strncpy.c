#include "shell.h"
/**
 * _strncpy - s
 * @dest: s
 * @src: s
 * @num: s
 * Return: s
 */
char *_strncpy(char *dest, const char *src, size_t num)
{
	size_t i;

	for (i = 0; i < num && src[i] != '\0'; i++)
		dest[i] = src[i];
	for (; i < num; i++)
		dest[i] = '\0';
	return (dest);
}
