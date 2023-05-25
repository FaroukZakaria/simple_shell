#include "shell.h"
/**
 * error - handles the getline error
 * Return: void
 */
int error(void)
{
	if (getline(&line, &size, stdin) == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			fflush(stdout);
			write(1, "\n", 1);
		}
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
/**
 * non_int - non interactive mode error
 * @vect: s
 * Return: s
 */
void non_int(char **vect)
{
	if ((!(isatty(STDIN_FILENO))) && (access(_bin(av[0]), X_OK) == -1))
	{
		if (_strcmp(av[0], "exit") == 0)
			exit(__exit());
		write(1, (vect[0]), _strlen(vect[0]));
		write(1, ": 1: ", _strlen(": 1: "));
		write(1, av[0], _strlen(av[0]));
		write(1, ": not found\n", _strlen(": not found\n"));
		exit(-1);
	}
}
