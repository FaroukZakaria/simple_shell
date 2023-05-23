#include "shell.h"
/**last_return - s
 * @val: s
 * Return: s
 */
void last_return(int val)
{
	int exit_status = (val >> 8) & 0xFF;

	write(1, _btoi(exit_status), _strlen(_btoi(exit_status)));
}
/**
 * **com_out - edit comments out
 * @str: s
 * Return: s
 */
char **com_out(char **str)
{
	int i = 0;

	for (i = 0; _strcmp(str[i], "#") != 0; i++)
	{
		continue;
	}
	for (; str[i] != NULL; i++)
	{
		free(str[i]);
	}
	str[i] = NULL;
	return (str);
}
