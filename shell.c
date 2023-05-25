#include "shell.h"
/**
 * main - displays prompts and handles errors
 * @argc: s
 * @argv: s
 * Return: 0
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	int status = 0;
	char *l;

	line = NULL;
	size = 0;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, ("#cisfun$ "), 9);
		if (error() == -1)
			break;
		if (line[_strlen(line) - 1] == '\n')
			line[_strlen(line) - 1] = '\0';
		av[0] = line;
		token();
		l = _bin(av[0]);
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
		pid = fork();
		if (pid == -1)
			perror("fork");
		else if (pid == 0)
		{
			if (_strcmp(av[0], "cd") != 0)
				(execve(l, av, environ));
			perror(av[0]);
			status = 2;
			free(l);
			exit(2);
		}
		else
			waitpid(pid, &status, 0);
		if (_strcmp(av[0], l) != 0)
			free(l);
	}
	free(line);
	return (status);
}
