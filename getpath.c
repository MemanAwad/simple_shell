#include "main.h"

/**
 * getpath - a function to get the path for the commands
 * @env: the environment variable
 * Return: the path value
 */

char *getpath(char **env)
{
	int i = 0;
	char *value = NULL;
	char *name = NULL;
	char *token = NULL;
	char *delm = "=\n";

	while (env[i] != NULL)
	{
		name = _strtok(env[i], delm);
		token = _strtok(NULL, delm);

		if (_strcmp(name, "PATH") == 0)
		{
			value = malloc(sizeof(char) * (_strlen(token) + 1));
			_strcpy(value, token);
			return (value);
		}
		i++;
	}
	return (NULL);
}
