#include "shell.h"
/**
 * _strtok - s
 * @str: s
 * @delim: s
 * Return: s
 */
char *_strtok(char *str, const char *delim)
{
	static char *savedStr;
	char *token;

	if (str != NULL)
	{
		savedStr = str;
	}
	token = savedStr;
	if (*token == '\0')
	{
		return (NULL);
	}
	while (*savedStr != '\0')
	{
		if (*savedStr == *delim)
		{
			*savedStr = '\0';
			savedStr++;
			return (token);
		}
		savedStr++;
	}
	return (token);
}
