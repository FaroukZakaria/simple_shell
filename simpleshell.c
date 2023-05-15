#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/**
 * main - main func
 * Return: 0 or 1
 */
int main(void)
{
	pid_t pid;
	int status;
	char *input;
	char *line = NULL;
	size_t l_size = 0;

	while (1)
	{
	{
		printf("$ ");
		getline(&line, &l_size, stdin);
		break;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execlp(input, input, NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	add_history(input);
	free(input);
}
return (0);
}
