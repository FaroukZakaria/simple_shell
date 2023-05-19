#include "shell.h"
/**
 * do_al - s
 * @str: s
 * @keys: s
 * @values: s
 * Return: s
 */
void do_al(char *str[], char *keys[], char *values[])
{
	int i = 0;
	char *split;
	/*char *avv;*/

	if (_strcmp(str[0], "alias") == 0)
	{
		printf("ALIAS!!!\n");
		for (i = 0; str[i] != NULL; i++)
		{
			split = _strchr(str[i], '=');
			if (split != NULL)
			{
				*split = '\0';
				keys[i] = str[i];
				values[i] = split + 1;
				printf("key: %s\n", keys[i]);
				printf("value: %s\n", values[i]);
			}
		}
		for (i = 0; values[i] != NULL; i++)
			values[i] = _strtok(values[i], "\'");
		printf("key: %s\n", keys[i]);
		printf("value: %s\n", values[i]);
	}
}
