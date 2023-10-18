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
	char *str = NULL, *delm = " \t\n";
	char *prompt = "($)";
	char *s = NULL;
	int what = -2;

	(void)ac, (void) av;
	while (1)
	{
		write(STDOUT_FILENO, prompt, 3);
		str = getstring();
		s = getcmd(str);
		if (s == NULL)
		{
			if (str[0] == '#')
			{
				free(str), free(s);
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
		free(s);

		tokens(str);
	}
}
