#include "main.h"

/**
 * handle_command - funtion to print an error to the user
 * @str: string that contains the command of the error
 * @delm: delimeter to get the command
 *
 * Return: void
 */
void handle_command(char *str, char *delm)
{
	char *token = NULL;
	char *error = ": command not found\n";
	(void)delm;
	token = strtok(str, delm);
	if (token != NULL)
	{
		write(STDERR_FILENO, token, _strlen(token));
		write(STDERR_FILENO, error, _strlen(error));
	}
	free(str);

}

/**
 * handle_command2 - funtion to print an error to the user
 * @str: string that contains the command of the error
 * @s: string to be freed
 * @arg: tha first element of argv
 *
 * Return: void
 */
void handle_command2(char *str, char *s, char *arg)
{
	char *error = ": 1: ";
	char *token = strtok(str, " \t\n");

	(void)s;
	if (token != NULL)
	{
		write(STDERR_FILENO, arg, _strlen(arg));
		write(STDERR_FILENO, error, _strlen(error));
		write(STDERR_FILENO, token, _strlen(token));
		error = ": not found\n";
		write(STDERR_FILENO, error, _strlen(error));
		free(str);
		free(s);

		exit(127);
	}
	else
	{
		free(str);
		free(s);
		exit(0);
	}
}

/**
 * tok_nums - function that return the number of the tokens
 * in the string of the command
 * @str: string that contains the command
 * @delm: the delimiter of the string
 *
 * Return: number of the tokens
 */
int tok_nums(char *str, char *delm)
{
	int count = 0;
	char *token = NULL;
	char *strcopy = NULL;

	strcopy = malloc(sizeof(char) * (_strlen(str) + 1));
	_strcpy(strcopy, str);
	token = strtok(strcopy, delm);

	while (token != NULL)
	{
		token = strtok(NULL, delm);
		count++;
	}
	free(strcopy);
	return (count);
}

/**
 * _tok - function that fill the array of the argument of the
 * execve function with tokens
 * @str: the string
 * @delm: delimater to toknize the string
 * @num: number of token to determine the size of the array
 *
 * Return: arrray of tokens
 */
char **_tok(char *str, char *delm, int num)
{
	char **tokens = malloc(sizeof(char *) * (num + 1));
	char *token = NULL;
	int i = 0;

	token = strtok(str, delm);
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, delm);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
