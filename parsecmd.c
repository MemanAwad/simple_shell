#include "main.h"

/**
 * getcmd - a function to get the command if it's there
 * @str: a string represent the command
 * Return: the result of the command
 */
char *getcmd(char *str)
{
	char *strcopy = malloc(sizeof(char) * (_strlen(str) + 1));
	char *result = NULL, *cmd = NULL, *delm = " \t\n";
	char *comand = NULL, *token = NULL;
	struct stat obj;

	comand = _strdup(str);
	token = _strtok(comand, delm);
	if (token == NULL)
	{
		free(strcopy);
		free(comand);
		return (NULL);
	}
	if (stat(token, &obj) == 0)
	{
		free(strcopy);
		return (comand);
	}
	free(comand);
	_strcpy(strcopy, str);
	cmd = _strtok(strcopy, delm);
	if (commands(cmd))
	{
		result = malloc(sizeof(char) * (_strlen(cmd) + 1));
		_strcpy(result, cmd);
		free(strcopy);
		return (result);
	}
	free(strcopy);
	return (NULL);
}

/**
 * commands - a function that check about the command
 * @cmd: the command
 * Return: 1 if it's exist, 0 if not.
 */


int commands(char *cmd)
{
	char **cmdarray = NULL;
	int i = 0;

	cmdarray = malloc(sizeof(char **) * 13 * (sizeof(char)));
	cmdarray[i++] = _strdup("ls");
	cmdarray[i++] = _strdup("cp");
	cmdarray[i++] = _strdup("mv");
	cmdarray[i++] = _strdup("rm");
	cmdarray[i++] = _strdup("grep");
	cmdarray[i++] = _strdup("cat");
	cmdarray[i++] = _strdup("mkdir");
	cmdarray[i++] = _strdup("chmod");
	cmdarray[i++] = _strdup("ps");
	cmdarray[i++] = _strdup("kill");
	cmdarray[i++] = _strdup("env");
	cmdarray[i++] = _strdup("exit");
	cmdarray[i++] = NULL;

	i = 0;
	while (cmdarray[i] != NULL)
	{
		if (_strcmp(cmd, cmdarray[i]) == 0)
		{
			freeEnv(cmdarray);
			return (1);
		}
		i++;
	}
	freeEnv(cmdarray);
	return (0);
}
/**
 * parsecmd - a function that parse if the command is exist or not
 * @str: input from terminal
 * @command: the command
 * Return: 1 in failure
 */


int parsecmd(char *str, char *command)
{
	char *token, *delm = " \t\n";
	int value = -1, count = 0;
	char *str2 = NULL;
	char *error = NULL;

	str2 = malloc(sizeof(char) * (_strlen(str) + 1));
	_strcpy(str2, str);
	token = _strtok(str2, delm);
	while (token != NULL)
	{
		count++, token = _strtok(NULL, delm);
	}
	if (count == 0)
	{
		free(str2), value = 1;
		return (value);
	}
	else if ((_strcmp(command, "exit") == 0))
	{
		free(str2), value = handle_exit(command, str, count);
		return (value);
	}
	else if (_strcmp(command, "env") == 0)
	{
		if (count > 1)
		{
			error = "env:";
			write(STDERR_FILENO, error, 0), free(str2);
			return (value);
		}
		_env();
		value = 4, free(str2);
		return (value);
	}
	else
		value = 0;
	free(str2);
	return (value);
}
