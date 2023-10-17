#include "main.h"

/**
 * nointershell - function to handle non interactive shell
 * @ac: number of arguments
 * @av: the array of arguments
 *
 * Return: void
 */
void nointershell(int ac, char **av)
{
	char *token, *str = NULL, *str2 = NULL, *delm = " \t\n";
	char *fullpath = NULL, *cmdpath = NULL;
	char *s = NULL, **k = NULL, *strr;
	int tok_num, i = 0, what = -2, pid;

	(void)ac, (void) av;
	tok_num = i =  pid = 0;
	while (1)
	{
		str = getstring();
		s = getcmd(str);
		if (s == NULL)
		{
			handle_command2(str, s, av[0]);
			free(s);
			continue;
		}
		what = parsecmd(str, s);
		if (what > 0)
		{
			free(s), free(str);
			continue;
		}
		str2 = malloc(sizeof(char) * (_strlen(str) + 1));
		_strcpy(str2, str);
		tok_num = tok_nums(str, delm);
		token = strtok(str2, delm);
		fullpath = _getenv("PATH");
		cmdpath = getpathvalue(fullpath, token);
		strr = malloc(sizeof(char) * (_strlen(str) + 1));
		_strcpy(strr, str);
		k = _tok(strr, delm, tok_num);
		free(fullpath);
		free(s), free(str), free(str2);
		s = str = fullpath = str2 = NULL;

		_fork(cmdpath, k);
	}
}

