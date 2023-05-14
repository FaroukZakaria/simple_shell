#include "shell.h"
/**
 * main - entry
 * Return: 0
 */
int main()
{
	char *line = NULL;
	ssize_t line_len = 0;
	ssize_t num_chars;
	char **args = split_input(line);

	while (1)
	{
		printf("$ ");
		num_chars = getline(&line, &line_len, stdin);

		if (num_chars == -1)
		{
			break;
		}

		if (line[num_chars - 1] == '\n')
		{
			line[num_chars - 1] = '\0';
		}

		execute_command(args);

		free(args);
	}

	free(line);

	return (EXIT_SUCCESS);
}
