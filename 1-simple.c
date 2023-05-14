#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
/**
 * main - displays prompts and handles errors
 * Return: 0
 */

int main()
{
	char *line = NULL;
	size_t size = 0;
	char *av[3] = {NULL, NULL, NULL};
	int env_count = 0;
	char **envp = malloc(sizeof(char*) * (env_count + 1));
	int status;
	char *args[21];
	int i = 0;
	char *token;
	pid_t pid;

	while (1)
	{
		printf("$ ");
		if (getline(&line, &size, stdin) == -1)
		{
			printf("\n");
			break;
		}
		token = strtok(line, " ");
		i = 0;
		while (token)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;

		if (line[strlen(line) - 1] == '\n')
		{
			line[strlen(line) - 1] = '\0';
		}
		av[0] = line;
		if (i > 0)
		{
			av[1] = args[1];
		}
		pid = fork();

		if (pid == -1)
		{
			perror("fork");
		}
		else if (pid == 0)
		{
			execve(av[0], av, envp);
			perror("execve");
			exit(1);
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}
	free(line);
	return (0);
}
