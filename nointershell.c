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
	char *str = NULL;
	char *s = NULL;
	int what = -2;

	(void)ac, (void) av;
	while (1)
	{
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
				handle_command2(str, s, av[0]);
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

