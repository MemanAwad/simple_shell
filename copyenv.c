#include "main.h"

/**
 * copyenv - a function to copy env
 * @env: to be copied
 * Return: a copy version from env
 */

char **copyenv(char **env)
{
	int i = 0;
	int len = 0;
	char **envcpy = NULL;
	char *ptr = NULL;

	while (env[i++] != NULL)
		len++;
	envcpy = malloc(sizeof(char **) * (len + 1) * sizeof(char));
	i = 0;
	while (env[i] != NULL)
	{
		ptr = env[i];
		envcpy[i] = malloc(sizeof(char *) * (_strlen(ptr) + 1));
		_strcpy(envcpy[i], ptr);
		i++;
	}
	envcpy[i] = NULL;
	return (envcpy);
}

/**
 * freeEnv - a function to free env
 * @env: to be freed
 */


void freeEnv(char **env)
{
	int i = 0;
	int len = 0;

	if (env == NULL)
		return;
	while (env[i++] != NULL)
	{
		len++;
	}
	for (i = 0; i < len; i++)
	{
		free(env[i]);
		env[i] = NULL;
	}
	free(env);
	env = NULL;
}
