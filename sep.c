#include "shell.h"
/**
 * sep - s
 * @str: s
 * Return: s
 */
void sep(char **str, char **_environ)
{
	int i = 0, j = 0, k = 0, l = 0, m = 0;
	char **str2, **str3;
	pid_t pid;
	int status;

	while (str[i] != NULL)
	{
		if (_strcmp(str[i], ";") == 0)
			k++;
		i++;
	}
	if (k == 0)
		return;
	while (l < k)
	{
		printf("current value of l is: %d\n", l);
		/*printf("value of i is: %d\n", i);*/
		str2 = malloc(sizeof(char *) * i);
		for (j = 0; _strcmp(str[j], ";") != 0; j++)
		{
			str2[j] = malloc(sizeof(char) * (_strlen(str[j])));
			_strcpy(str2[j], str[j]);
		}
		/*printf("j before i add is: %d\n", j);*/
		j++;
		str3 = malloc(sizeof(char *) * ((i - j)));
		for (m = 0; j < i; j++, m++)
		{
			str3[m] = malloc(sizeof(char) * (_strlen(str[j])));
			_strcpy(str3[m], str[j]);
			free(str2[j]);
		}
		str2[j] = NULL;
		str3[m] = NULL;
		/**for (i = 0; str3[i] != NULL; i++)
			printf("str3 is: %s\n", str3[i]);*/
		str = str3;
		l++;
		/**for (i = 0; str2[i] != NULL; i++)
			printf("to be executed %s\n", str2[i]);*/
		pid = fork();
		if (pid == 0)
		{
			sleep(1);
			printf("GONNA EXECUTE NOW!!!\n");
			execve(_bin(str2[0]), str2, _environ);
			perror("STUPID");
			exit(1);
		}
		else if (pid == -1)
			perror("fork");
		else
		{
			waitpid(pid, &status, 0);
			printf("does this even execute?");
			printf("\n what about this?");
		}
	}
	free(str2);
	free(str3);
	return;
}
