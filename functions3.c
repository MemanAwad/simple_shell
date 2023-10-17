#include "main.h"

/**
 * _atoi - function that convert a string of ascci values to an integer
 * if the string contains ascci values < 57 or < 48 it returns 0
 * @str: the string to be converted
 *
 * Return: and integer value of the string or 0
 */
int _atoi(const char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	if (str == NULL)
		return (0);
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}

	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		result = ((result * 10) + (str[i] - '0'));
		i++;
	}
	result = result * sign;

	return (result);
}

/**
 * _strchr - function search for a charachter in the string
 * then return a pointer to the first occurance of c in the string
 * @str: the string to search in
 * @c: the char we are looking for
 *
 * Return: a pointer to the char or null if not found
 */
char *_strchr(const char *str, int c)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
		{
			/* return a pointer to c if its found */
			return ((char *)&str[i]);
		}
		i++;
	}
	/* if c is null terminator return null terminator of the string */
	if (c == '\0')
	{
		return ((char *)&str[i]);
	}
	return (NULL);

}

/**
 * _strncpy - a function that copies n chars from a string
 * @dest: the copy string
 * @src: tge original string
 * @n: chars number to be copies
 * Return: the copy string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for (; i < n; i++)
		dest[i] = '\0';
	return (dest);
}


