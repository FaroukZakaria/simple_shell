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
		if (_strcmp(av[0], "exit") == 0)
		{
			status = __exit();
			break;
		}
		short_cd(av[0]);
		_pid_get(av);
		ch_var(av);
		non_int(argv);
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
			status = 2;
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}
	free(line);
	return (status);
}
