#include "main.h"

/**
 * _getenv - function that return the vallue of the given
 * enviroment variable
 * @variable: the enviroment variable
 *
 * Return: the value of the enviroment variable
 */
char *_getenv(char *variable)
{
	int i = 0;
	char *value = NULL;
	char *name = NULL;
	char *token = NULL;
	char *delm = "=\n";
	char *temp = NULL;
	char **env = environ;

	while (env[i] != NULL)
	{
		temp = _strdup(env[i]);
		name = _strtok(temp, delm);
		token = _strtok(NULL, delm);


		if (_strcmp(name, variable) == 0)
		{
			value = malloc(sizeof(char) * (_strlen(token) + 1));
			_strcpy(value, token);
			free(temp);
			return (value);
		}
		free(temp);
		i++;
	}
	return (NULL);
}

/**
 * getpathvalue - function that return the path of the
 * given command
 * @path: the value of the path enviroment variable
 * @a: the command
 *
 * Return: the path of the command
 */
char *getpathvalue(char *path, char *a)
{
	char *token = NULL, *fullpath = NULL;
	char *delm = ":";
	struct stat obj;
	char *pathcopy =  NULL;

	pathcopy = malloc(sizeof(char) * (_strlen(path) + 1));

	if (access(a, X_OK) == 0 && stat(a, &obj) == 0)
	{
		free(pathcopy);
		fullpath = malloc(sizeof(char) * (_strlen(a) + 1));
		_strcpy(fullpath, a);
		return (fullpath);
	}
	_strcpy(pathcopy, path);
	token = _strtok(pathcopy, delm);
	while (token != NULL)
	{
		fullpath = malloc(sizeof(char) * (_strlen(token) + _strlen(a) + 2));
		_strcpy(fullpath, token);
		_strcat(fullpath, "/");
		_strcat(fullpath, a);
		if (stat(fullpath, &obj) == 0)
		{
			free(pathcopy);
			return (fullpath);
		}
		else
		{
			free(fullpath);
			fullpath = NULL;
			token = _strtok(NULL, delm);
		}

	}
	free(pathcopy);
	return (NULL);
}
