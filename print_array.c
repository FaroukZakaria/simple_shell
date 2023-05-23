#include "shell.h"
/**
 * print_array - prints array lol
 * @array: the char **
 * Return: void
 */
void print_array(char **array)
{
	int i = 0;

	if (array == NULL)
		return;
	for (i = 0; array[i] != NULL; i++)
		printf("%s\n", array[i]);
}
