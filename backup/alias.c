#include "shell.h"
/**
 * do_al - s
 * @string: s
 * @name: s
 * @value: s
 * Return: s
 */
void do_al(const char *string[], char **name, char **value)
{
	int i = 0, j = 0;
	char *key = NULL;
	char *val = NULL;

	for (i = 0; string[i] != NULL; i++)
	{
		key = strtok(string[i], "=");
		val = strtok(NULL, "=");
		if (key != NULL && val != NULL)
		{
			*name = _strdup(key);
			*value = _strdup(val);
		}
	}
}
/**
 * ch_al - s
 * Return: s
 */
void ch_al(char *string, char **name, char **value)
{
	int j;
	
	for (j = 0; string[j] != NULL; j++)
	{
		if (_strcmp(string[j], *name[j]) == 0)
		{
			string[j] = *value[j];
		}
	}
}
