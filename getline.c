#include "main.h"

/**
 * getstring - function to read the entered command
 * using getline function
 *
 * Return: the read string
 */
char *getstring(void)
{
	int nread = 0;
	char *str = NULL;
	size_t len = 0;

	nread = getline(&str, &len, stdin);
	if (nread == -1)
	{
		free(str);
		exit(0);
	}
	return (str);
}
