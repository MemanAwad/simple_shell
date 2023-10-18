#include "main.h"

/**
 * intershell - a function to handle the internal shell commands
 * @ac: the number of the argument
 * @av: the array of argument
 *
 * Return: void
 */
void intershell(int ac, char **av)
{
	char *token, *str = NULL, *str2 = NULL, *delm = " \t\n";
	char *fullpath = NULL, *cmdpath = NULL, *prompt = "($)";
	char *s = NULL, **k = NULL, *strr;
	int tok_num, i = 0, what = -2, pid;

	(void)ac, (void) av;
	tok_num = i =  pid = 0;
	while (1)
	{
		write(STDOUT_FILENO, prompt, 3);

		str = getstring();
		s = getcmd(str);
		if (s == NULL)
		{
			if (str[0] == '#')
			{
				free(str), free(s);;
				continue;
			}
			else
			{
				handle_command(str, delm);
				free(s);
				continue;
			}
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
		token = _strtok(str2, delm);
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
