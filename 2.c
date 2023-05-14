#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
  char *input;
  pid_t pid;
  int status;

  while(1) {
    // read input from user
    input = readline("> ");

    // exit if user inputs "exit" or "quit"
    if (strcmp(input, "exit") == 0 || strcmp(input, "quit") == 0) {
      break;
    }

    // fork a child process
    pid = fork();

    if (pid == -1) {
      perror("fork");
      exit(EXIT_FAILURE);
    } else if (pid == 0) {
      // execute command in child process
      execlp(input, input, NULL);
      // if execlp returns, there was an error
      perror("execlp");
      exit(EXIT_FAILURE);
    } else {
      // wait for child process to finish
      waitpid(pid, &status, 0);
    }

    // add input to command history
    add_history(input);
    // free input buffer allocated by readline
    free(input);
  }

  return 0;
}

