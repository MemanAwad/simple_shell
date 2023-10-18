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
 * isdelim - function checks if the given charachter is a delimiter
 * @delim: the string of the delimiter charachters
 * @c: the char to be checked if he is a dilimiter or not
 *
 * Return: 0 if c is not a delimiter 1 if it is
 */
int isdelim(const char *delim, char c)
{
	int i = 0;
	int len = strlen(delim);

	while (i < len)
	{
		if (delim[i] == c)
			return (1);
		i++;
	}
	return (0);
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

	if (string == NULL)
		string = ptr;
	else
		ptr = string;

	if (string == NULL)
		return (NULL);

	while (string[i] != '\0')
	{
		if (isdelim(delim, string[i]))
			i++;
		else
			break;
	}
	if (string[i] == '\0')
		return (NULL);
	start = &string[i++];
	while (1)
	{
		if (string[i] == '\0')
		{
			ptr = &string[i];
			return (start);
		}
		if (isdelim(delim, string[i]))
		{
			string[i] = '\0';
			ptr = &string[i + 1];
			return (start);
		}
		i++;
	}

}
