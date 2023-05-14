#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
/**
 * main - main func
 * Return: 0 or 1
 */
int main(void)
{
	pid_t pid;
	int status;
	char *input;

	while (1)
	{
	{
		input = readline("Enter command or  'exit' to quit\n> ");
		if (strcmp(input, "exit") == 0 || strcmp(input, "quit") == 0)
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
