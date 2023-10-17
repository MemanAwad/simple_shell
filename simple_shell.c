#include "main.h"
/**
 * main - funcstion to run the simple shell
 * @ac: number of arguments
 * @av: the array of argument
 * @envp:the array of the enviroment variable
 *
 * Return: Always 0
 */
int main(int ac, char **av, char *envp[])
{
	(void)envp;

	if (isatty(STDIN_FILENO) == 1)
	{
		intershell(ac, av);
	}
	else
	{
		nointershell(ac, av);
	}

	return (0);
}
