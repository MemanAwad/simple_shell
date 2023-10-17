#include "main.h"

/**
 * _fork - function to create a child process the use execve function
 * @arg: array of argument to execvw function
 * @cmd: command to execute
 * Return: always 0
 */
int _fork(char *cmd, char **arg)
{
	int pid = -1;
	char **env = environ;
	char *error = NULL;
	int status;

	pid = fork();
	if (pid == 0)
	{
		execve(cmd, arg, env);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			error = "process exit with non zero value\n";
			write(STDERR_FILENO, error, 0);
			free(cmd), free(arg[0]), free(arg);
			cmd = NULL, arg = NULL;
			exit(2);
		}
		free(cmd), free(arg);
		cmd = NULL, arg = NULL;

	}
	return (status);
}
