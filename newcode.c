#include "shell.h"
/**
 * main - displays prompts and handles errors
 * Return: 0
 */
int main(void)
{
	char **envp = malloc(sizeof(char *) * (env_count + 1));

	line = NULL;
	size = 0;
	env_count = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		if (error() == -1)
			break;
		if (line[_strlen(line) - 1] == '\n')
			line[_strlen(line) - 1] = '\0';
		av[0] = line;
		if (_strcmp(av[0], "exit") == 0)
			break;
		token();
		pid = fork();
		if (pid == -1)
			perror("fork");
		else if (pid == 0)
		{
			execve(av[0], av, envp);
			perror(av[0]);
			exit(1);
		}
		else
			waitpid(pid, &status, 0);
	}
	free(line);
	return (0);
}
