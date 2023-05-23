#include "shell.h"
/**
 * hash_q - s
 * @str: s
 * Return: s
 */
int hash_q(char **str, int val)
{
	int i = 1;

	for (i = 1; str[i] != NULL; i++)
	{
		if (str[i][0] == '$')
		{
			if (str[i][1] == '?')
			{
				str[i] = last_return(val);
			}
		}
	}
	return (-1);
}
