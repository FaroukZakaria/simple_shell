#include "shell.h"
/**
 * _atoi - s
 * @str: s
 * Return: s
 */
int _atoi(char *str)
{
	int result = 0;
	int sign = 1;

	while (*str == ' ' || *str == '\t')
	{
		str++;
	}
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
