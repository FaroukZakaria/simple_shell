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
 * @str: s
 * @bin: s
 * Return: s
 */
int non_int(char **vect, char **str, char *bin)
{
	int stat;

	if ((!(isatty(STDIN_FILENO))) && (access(bin, X_OK) == -1) && (access(str[0], X_OK) == -1))
	{
		if (_strcmp(str[0], "exit") == 0)
		{
			stat = __exit();
			if (stat == -1)
			{
				write(1, (vect[0]), _strlen(vect[0]));
				write(1, ": 1: ", _strlen(": 1: "));
				write(1, str[0], _strlen(str[0]));
				write(1, ": Illegal number: ", _strlen(": Illegal number: "));
				write(1, av[1], _strlen(av[1]));
				write(1, "\n", 1);
				return (2);
			}
		}
		write(1, (vect[0]), _strlen(vect[0]));
		write(1, ": 1: ", _strlen(": 1: "));
		write(1, str[0], _strlen(str[0]));
		write(1, ": not found\n", _strlen(": not found\n"));
		return (2);
	}
	return (0);
}
