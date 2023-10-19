#include "main.h"

/**
 * errmsg - function ti print error msg in STDERR
 * @str: string used in the message
 * @av: array of arguments
 * Return: void
 */
void errmsg(char *str, char **av)
{
	char *error;
	char *err;
	char *token;

	err = _strdup(str);
	token = _strtok(err, " \n\t");
	token = _strtok(NULL, " \n\t");
	if (isatty(STDIN_FILENO) == 1)
	{
		error = "exit: Illegal number: ";
		write(STDERR_FILENO, error, _strlen(error));
		write(STDERR_FILENO, token, _strlen(token));
		error = "\n";
		write(STDERR_FILENO, error, _strlen(error));
	}
	else
	{	error = ": 1: exit: Illegal number: ";
		write(STDERR_FILENO, av[0], _strlen(av[0]));
		write(STDERR_FILENO, error, _strlen(error));
		write(STDERR_FILENO, token, _strlen(token));
		error = "\n";
		write(STDERR_FILENO, error, _strlen(error));

	}
	free(err);

}
/**
 * check - function to check if the string contains just numbers
 * @str: the string
 *
 * Return: -1 if its not just integers 0 if it is
 */
int check(char *str)
{
	int i = 0;
	int len = _strlen(str);

	for (i = 0; i < len; i++)
	{
		if (str[i] < 48 || str[i] > 57)
			return (-1);
	}
	return (0);
}

/**
 * exitshell - function to exit shell with a specific value
 * @status: the exit status
 *
 * Return: void
 */
void exitshell(int status)
{
	exit(status);
}

/**
 * handle_exit - function to handle the exit command in the shell
 * @str: the command used to exit the shell
 * @n: number of argument to exit command
 * @command: the exit command
 * Return: integer value large than 1 if there is error
 */
int handle_exit(char *command, char *str, int n, char **av)
{
	int count = n, exitval, value = 1, checkk = 1;
	char *token = NULL, *delm = " \n", *strcopy, *error;

	strcopy = _strdup(str);
	if (count == 1)
	{
		free(str), free(command), free(strcopy);
		exitshell(0);
	}
	else if (count > 1)
	{

		token = _strtok(strcopy, delm);
		token = _strtok(NULL, delm);
		checkk = check(token);
		if  (checkk == 0)
		{
			if (count > 2)
			{
				error = "-bash: exit: too many arguments\n";
				write(STDERR_FILENO, error, _strlen(error));
				free(strcopy);
				return (value);
			}
			exitval = _atoi(token);
			if (exitval < 0)
			{
				errmsg(str, av), free(strcopy);
				return (3);
			}
			free(str), free(strcopy), free(command), exitshell(exitval);
		}
		else
		{
			errmsg(str, av), free(strcopy);
			return (3);
		}
	}
	return (3);
}
