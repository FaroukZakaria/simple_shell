#ifndef SHELL_H
#define SHELL_H
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char *get_input(void);
size_t _strlen(const char *str);
void token(void);
int error(void);
void last_line(void);
char **split_input(char *input);
int execute_command(char **arguments);
char *av[3];
char *line;
size_t size;
int env_count;
int status;
pid_t pid;
int shell_1(void);
int shell_2(void);
#endif
