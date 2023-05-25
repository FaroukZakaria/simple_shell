#include "shell.h"
/**
 * main - displays prompts and handles errors
 * Return: 0
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	size = 0;
	while (1)
	{
		line = NULL;
		if (isatty(STDIN_FILENO))
			write(1, ("#cisfun$ "), 9);
		if (error() == -1)
			break;
		if (line[_strlen(line) - 1] == '\n')
			line[_strlen(line) - 1] = '\0';
		line = trim(line);
		av[0] = trim(line);
		token();
		non_int(argv);
		if (_strcmp(av[0], "exit") == 0)
			break;
		short_cd(av[0]);
		_pid_get(av);
		ch_var(av);
		pid = fork();
		if (pid == -1)
			perror("fork");
		else if (pid == 0)
		{
			if (_strcmp(av[0], "cd") != 0)
			{
				(execve(_bin(av[0]), av, environ));
			}
			perror(av[0]);
			break;
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}
	return (0);
}
