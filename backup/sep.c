#include "shell.h"
/**
 * sep - s
 * @str: s
 * Return: s
 */
void sep(char *str[])
{
	int i = 0, j = 0, k = 0;
	char **str2 = NULL;

	while (str[i] != NULL)
	{
		if (_strcmp(str[i], ";") == 0)
		{
			i++;
			j = 0;
			k = 0;
			while (str2[k] != NULL)
			{
				printf("%s\n", str2[k]);
			}
			execve(_bin(str2[0]), str2, environ);
			str2 = NULL;
		}
		else
		{
			str2[j] = str[i];
			j++;
			i++;
		}
	}
}
