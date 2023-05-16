#include "shell.h"
/**
 * _strncmp - s
 * @s1: s
 * @s2: s
 * @n: s
 * return: 0
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		else if ((s1[i] == '\0'))
		{
			return (0);
		}
	}
	return (0);
}		
