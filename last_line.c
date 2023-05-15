#include "shell.h"
/**
 * last_line - replaces last line with null
 * Return: void
 */
void last_line(void)
{
	if (line[_strlen(line) - 1] == '\n')
	{
		line[_strlen(line) - 1] = '\0';
	}
}
