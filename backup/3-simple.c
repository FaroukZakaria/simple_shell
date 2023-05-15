#define MAX_ARGS 64
#define MAX_LINE 1024

char **split_input(char *line) {
	int i = 0;
	char *token;
	char **tokens = malloc(MAX_ARGS * sizeof(char *));

	if(tokens == NULL) {
		perror("Error: could not allocate memory");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\n");

	while(token != NULL) {
		tokens[i] = token;
		i++;

		if(i >= MAX_ARGS) {
			break;
		}

		token = strtok(NULL, " \t\n");
	}

	tokens[i] = NULL;

	return tokens;
}

void execute_command(char **args)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("Error:");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("Error:");
	}
	else
	{
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			{
				waitpid(pid, &status, WUNTRACED);
			}
	}
}
