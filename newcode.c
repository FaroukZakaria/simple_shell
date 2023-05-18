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
			break;
		if (line[_strlen(line) - 1] == '\n')
			line[_strlen(line) - 1] = '\0';
		av[0] = line;
		token();
		if (__exit())
			exit(__exit());
		pid = fork();
		if (pid == -1)
			perror("fork");
		else if (pid == 0)
		{
			_cd();
			(execve(_bin(av[0]), av, environ));
			perror(av[0]);
			exit(1);
		}
		else
			waitpid(pid, &status, 0);
	}
	free(line);
	return (0);
}
