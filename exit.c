#include "shell.h"
/**
 * __exit - s
 * Return: s
 */
int __exit(void)
{
	int status = 0;

	if (_strcmp(av[0], "exit") == 0)
	{
		if (av[1] != NULL)
		{
			if (av[1][0] == '-')
				return (-1);
			if ((_is_digit(av[1])) == 0)
				return (-1);
			status = _atoi(av[1]);
			return (status);
		}
	}
	return (status);
}
/**
 * _is_digit - s
 * @str: s
 * Return: s
 */
int _is_digit(char *str)
{
	int i = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] < '0') || (str[i] > '9'))
			return (0);
	}
	return (1);
}
