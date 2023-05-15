#include "shell.h"
/**
 * esc - exits shell
 * Return: 0 , 1
 */
int esc(void)
{
	if (av[0] == "exit")
	{
		return (1);
	}
	return (0);
}
