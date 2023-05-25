#include "shell.h"
/**
 * trim - trims spaces
 * @str: s
 * Return: s
 */
char *trim(char *str)
{
	int i = 0, j = 0, space_found = 0;

	while (str[i] == ' ')
	{
		str++;
	}
	for (i = 0, j = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
		{
			if (!space_found)
			{
				str[j++] = str[i];
				space_found = 1;
			}
		}
		else
		{
			str[j++] = str[i];
			space_found = 0;
		}
	}
	str[j] = '\0';
	return (str);
}
