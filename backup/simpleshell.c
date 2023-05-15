#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"
/**
 * main - main func
 * Return: 0 or 1
 */
int main(void)
{
	pid_t pid;
	int status;
	char *args[2], *line = NULL;
	size_t l_size = 0;
	ssize_t read;

	while (1)
	{
		printf("$ ");
		read = getline(&line, &l_size, stdin);
		if (read == -1)
		{
			break;
		}
		if (line[0] != '\n')
		{
			line[_strlen(line) - 1] = '\0';
		}
		args[0] = line;
		args[1] = NULL;

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			execvp(args[0], args);
			perror("execvp");
			exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}
	free(line);
	return (0);
}
