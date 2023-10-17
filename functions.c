#include "main.h"
/**
 * _strlen - a function that calculate the length if a string
 * @str: the string to calculate it's length
 * Return: the length
 */
int _strlen(char *str)
{
	int count = 0;

	int i = 0;

	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		i++;
		count++;
	}
	return (count);
}



/**
 * _strcat - a function that concatnate two strings
 * @dest: first string
 * @str: second string
 * Return: pointer to  a string holds both
 */
char *_strcat(char *dest, char *str)
{
	int i = 0, j = 0;

	for (i = 0; dest[i] != '\0'; i++)
		;
	while (str[j] != '\0')
	{
		dest[i] = str[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcpy - a function that copies a string
 * @dest: the copy string
 * @src: the original string
 * Return: pointer to the destination string
 */
char *_strcpy(char *dest, char *src)
{
	int i = -1;

	do {
		i++;
		dest[i] = src[i];
	} while (src[i] != '\0');
	return (dest);
}

/**
 * _strcmp - a function that compare between two strings
 * @str1: the first string
 * @str2: the second string
 * Return: an integer represent the diferent between their ascii code
 */

int _strcmp(char *str1, char *str2)
{
	int comp = 0, i = 0;

	while (str1[i] != '\0')
	{
		if (str1[i] == str2[i])
			i++;
		else if (str1[i] > str2[i])
		{
			comp = str1[i] - str2[i];
			break;
		}
		else
		{
			comp = str1[i] - str2[i];
			break;
		}
	}

	return (comp);
}



/**
 * _strdup - a function that duplecate a string
 * @str: the string to be duplecate
 * Return: pointer to duplecated string
 */


char *_strdup(char *str)
{
	int i = 0;
	int len = 0;
	char *dup = NULL;

	len = strlen(str);
	dup = malloc(sizeof(char) * (len + 1));

	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

