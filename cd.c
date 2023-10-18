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
			p = _getenv("OLDPWD");
			_cd(p);
			free(p);
			return (0);
		}
		else
		{
			p = _getenv(path);
			_cd(p);
			free(p);
			return (0);
		}
	}
	return (0);


}


