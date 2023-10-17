#include "main.h"

/**
 * _env - function that print the enviroment variables
 *
 * Return: void
 */
void _env(void)
{
	int i = 0;
	char **env = environ;

	while (*env)
	{
		i = 0;
		while ((*env)[i] != '\0')
			i++;


		write(1, *env, i);
		write(1, "\n", 1);
		env++;
	}
}
/**
 * _strtok - function that tokenizing the string based on a given
 * delimiter if the string is null it will continue tkenizing
 * lastest string
 * @string: the string to be tokenized
 * @delim: the delimater to tokenize the string
 *
 * Return: the first token of the string
 */
char *_strtok(char *string, const char *delim)
{
	static char *ptr;
	char *start = NULL;
	int i = 0;
	char c = 0;

	if (string != NULL)
	{
		ptr = string;
	}
	else
	{
		string = ptr;
	}
	while (string[i] != '\0')
	{
		c = string[i];

		if (_strchr(delim, c) == 0)
		{
			start = &string[i];
			i++;
			break;
		}
	}
	c = string[i];
	while ((_strchr(delim, c) == 0))
	{
		i++;
		c = string[i];
	}
	string[i++] = '\0';
	c = string[i];
	while (!(_strchr(delim, c) == 0) && c != '\0')
	{
		i++;
		c = string[i];
	}
	ptr = &string[i];
	return (start);
}
