#include "shell.h"
/**
 * _memcpy - copies values of strings
 * @dest: s
 * @src: s
 * @n: s
 * Return: dest
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
	char *d = dest;
	const char *s = src;

	while (n-- > 0)
	{
		*d++ = *s++;
	}
	return (dest);
}
