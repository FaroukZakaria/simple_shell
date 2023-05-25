#include "shell.h"
/**
 * do_free - s
 * @str: s
 * Return: s
 */
void do_free(char **str)
{
	int i = 0;

	for (i = 0; str[i] != NULL; i++)
	{
		free(str[i]);
	}
}
