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
	char *p = NULL, *error = NULL;
	(void)command;
	if (n == 1)
	{
		p = _getenv("HOME");
		_cd(p);
		free(p);
		return (0);
	}
	else if (n == 2)
	{
		if (_strcmp(path,"-") == 0)
		{
			p = getenv("OLDPWD");
			_cd(p);
			return (0);
		}
		else
		{
			p = getenv(path);
			_cd(p);
			return (0);
		}
	}
	else 
	{
		error = "bash: cd: too many arguments\n";
		write(STDERR_FILENO, error, _strlen(error));
	}
	return (0);


}


