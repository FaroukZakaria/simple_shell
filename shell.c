#include "shell.h"
/**
 * main - displays prompts and handles errors
 * Return: 0
 */
int main(void)
{
	line = NULL;
	size = 0;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, ("#cisfun$ "), 9);
		if (error() == -1)
		{
			free(line);
			exit(-1);
		}
		if (line[_strlen(line) - 1] == '\n')
			line[_strlen(line) - 1] = '\0';
		av[0] = line;
		token();
		if (_strcmp(av[0], "exit") == 0)
		{
			free(line);
			exit(0);
		}
		if (_strcmp(av[0], "cd") == 0)
		{
			if (opendir(_cd()) != 0)
				chdir(_cd());
		}
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
			exit(1);
		}
		else
			waitpid(pid, &status, 0);
	}
	free(av[0]);
	free(av[1]);
	free(line);
	return (0);
}
