#include "main.h"

/**
 *
 */
int _cd(char *path)
{
	return (chdir(path));
}


int handle_cd(char *command, char *path, int n)
{
	char *p = NULL;
	char *token, *error;
	char *strr = _strdup(path);

	(void)command;
	token = _strtok(strr, " \t\n");
	token = _strtok(NULL, " \t\n");
	if (n == 1)
	{
		p = _getenv("HOME");
		chdir(p);
		write(STDOUT_FILENO, p, _strlen(p));
		error = "\n";
		write(STDOUT_FILENO, error, _strlen(error));
		free(strr);
		free(p);
		return (0);
	}
	else if (n == 2)
	{
		if (_strcmp(token, "-") == 0)
		{
			p = getenv("OLDPWD");
			_cd(p);
			write(STDOUT_FILENO, p, _strlen(p));
			error = "\n";
			write(STDOUT_FILENO, error, _strlen(error));
			free(strr), free(p);
			return (0);
		}
		else
		{
			if (access(token, X_OK) == 0)
			{
				_cd(token);
				write(STDOUT_FILENO, token, _strlen(token));
				error = "\n";
				write(STDOUT_FILENO, error, _strlen(error));
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
			}
		}
	}
	else 
	{
		error = "bash: cd: too many arguments\n";
		write(STDERR_FILENO, error, _strlen(error));
	}
	free(strr);
	return (0);
}


