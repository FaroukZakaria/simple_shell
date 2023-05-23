#ifndef SHELL_H
#define SHELL_H
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <dirent.h>

char *get_input(void);
size_t _strlen(const char *str);
void token(void);
int error(void);
int esc(void);
void last_line(void);
char *_strdup(const char *str);
void *_memcpy(void *dest, const void *src, size_t n);
void _strcat(char *dest, const char *src);
void _strcpy(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
char *_strchr(char *str, int n);
char *_strtok(char *str, const char *delim);
extern char **environ;
int _atoi(char *str);
int __exit(void);
char *_bin(char *str);
char *_cd(void);
void sep(char **str, char **_environ);
char **ch_var(char **envir);
char *_var(char *envar);
char *_getenv(const char *name);
void print_array(char **array);
void do_al(char *str[], char *keys[], char *values[]);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_getenv(const char *name);
char **path(void);
char **envp();
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
