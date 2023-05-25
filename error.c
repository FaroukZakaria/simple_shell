#include "shell.h"
/**
 * error - handles the getline error
 * Return: void
 */
int error(void)
{
	if (getline(&line, &size, stdin) == -1)
	{
		printf("\n");
		return (-1);
	}
	return (0);
}
/**
 * signal_c_action - s
 * @sign: s
 * Return: s
 */
void signal_c_action(int sign)
{
	if (sign == SIGINT)
		flag = 1;
}
