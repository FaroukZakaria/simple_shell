#include "shell.h"
/**
 * short_checks - shortens the checkers of the line and stuff
 * @l: s
 * @av: s
 * @status: s
 * @argv: s
 * @line: s
 * Return: s
 */
void short_checks(char *l, char **av, int status, char **argv, char *line)
{
	if (_strcmp(av[0], "exit") == 0)
	{
		if ((__exit() == -1) && (!(isatty(STDIN_FILENO))))
		{
			status = non_int(argv, av, l);
			free(line);
			free(l);
			exit(status);
		}
		status = __exit();
		free(line);
		free(l);
		exit(status);
	}
	short_cd(av[0]);
	_pid_get(av);
	ch_var(av);
	if ((non_int(argv, av, l)) == 2)
	{
		status = 2;
		free(line);
		free(l);
		exit(status);
	}
}
