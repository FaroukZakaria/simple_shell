#include "shell.h"
/**
 * _strcmp - s
 * @s1: s
 * @s2: s
 * Return: s1-s2
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			return ((*s1 - *s2));
		}
		s1++;
		s2++;
	}
	return ((*s1 - *s2));
}
