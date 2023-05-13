#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
int main()
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("Error\n");
		return (1);
	}
	else if (pid == 0)
	{
		printf("Child process\n");
		return (0);
	}
	else
	{
		wait(&status);
		printf("parrent process id %d", pid);
		return (0);
	}
}
