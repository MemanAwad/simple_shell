#include "main.h"

/**
 * handle_cd2 - function to handle the command cd with argument
 * @str: the command
 *
 * Return: Always 0
 */
int handle_cd2(char *str)
{
	char *strr = _strdup(str);
	char *token, *p, *error;

	token = _strtok(strr, " \t\n");
	token = _strtok(NULL, " \t\n");

	if (_strcmp(token, "-") == 0)
	{
		error = "\n";
		p = _getenv("OLDPWD");
		write(STDOUT_FILENO, p, _strlen(p));
		write(STDOUT_FILENO, error, _strlen(error));
		if (p != NULL)
			_cd(p);
		free(strr), free(p);
		return (0);
	}
	else
	{
		if (access(token, X_OK) == 0)
		{
			_cd(token);
			free(strr);
			return (0);
		}
		else
		{
			error = "./hsh: 1: cd: can't cd to ";
			write(STDERR_FILENO, error, _strlen(error));
			write(STDERR_FILENO, token, _strlen(token));
			error = "\n";
			write(STDERR_FILENO, error, _strlen(error));
			free(str);
		}
	}
	return (0);
}
/**
 * _cd - function to call shdir funcion
 * @path: the path we want to go to
 *
 * Return: the status of the function
 */
int _cd(char *path)
{
	return (chdir(path));
}

/**
 * handle_cd - function to handle built_in cd command
 * @command: the cd command
 * @path: the command
 * @n: number of argument to the command
 *
 * Return: Always 0
 */
int handle_cd(char *command, char *path, int n)
{
	char *p = NULL;
	char *error;

	(void)command;
	if (n == 1)
	{
		p = _getenv("HOME");
		if (p != NULL)
			_cd(p);
		free(p);
		return (0);
	}
	else if (n == 2)
	{
		handle_cd2(path);
	}
	else
	{
		error = "bash: cd: too many arguments\n";
		write(STDERR_FILENO, error, _strlen(error));
	}
	return (0);
}


