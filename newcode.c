#include "shell.h"
/**
 * main - displays prompts and handles errors
 * Return: 0
 */
int main(int argc, char *arrv[])
{
	line = NULL;
	size = 0;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, ("#cisfun$ "), 9);
		if (!(isatty(STDIN_FILENO)) && argc >= 2)
		{
			write(STDERR_FILENO, arrv[2], _strlen(arrv[2]));
			write(STDERR_FILENO, " 1: ", _strlen(" 1: "));
		}
		if (error() == -1)
			break;
		if (line[_strlen(line) - 1] == '\n')
			line[_strlen(line) - 1] = '\0';
		av[0] = line;
		token();
		if (_strcmp(av[0], "exit") == 0)
			exit(__exit());
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
				/*sep(av, environ);*/
				(execve(_bin(av[0]), av, environ));
			}
			perror(av[0]);
			exit(1);
		}
		else
			waitpid(pid, &status, 0);
	}
	free(line);
	return (0);
}
