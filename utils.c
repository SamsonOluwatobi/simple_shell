#include "shell.h"

/**
* samife_strdup - Duplicate a string and return a
* pointer to the newly allocated memory.
*
* @str: Pointer to a string
* Return: Pointer to a duplicated string
*/
char *samife_strdup(char *str)
{
	int i, length;

	char *new_str;

	if (!str)
	{
		return (NULL);
	}
	for (length = 0; str[length] != '\0';)
	{
		length++;
	}
	new_str = malloc(sizeof(char) * (length + 1));
	if (!new_str)
	{
		return (NULL);
	}
	for (i = 0; i < length; i++)
	{
		new_str[i] = str[i];
	}
	new_str[length] = '\0';
	return (new_str);
}

/**
* concatenate_strings - Concatenate three strings
* into a newly allocated memory.
*
* @name: First string
* @sep: Second string
* @value: Third string
* Return: Pointer to the concatenated string
*/
char *concatenate_strings(char *name, char *sep, char *value)
{
	char *result;

	int length1, length2, length3, i, k;

	length1 = samife_strlen(name);
	length2 = samife_strlen(sep);
	length3 = samife_strlen(value);

	result = malloc(length1 + length2 + length3 + 1);
	if (!result)
		return (NULL);

	for (i = 0; name[i]; i++)
		result[i] = name[i];
	k = i;

	for (i = 0; sep[i]; i++)
		result[k + i] = sep[i];
	k = k + i;

	for (i = 0; value[i]; i++)
		result[k + i] = value[i];
	k = k + i;

	result[k] = '\0';

	return (result);
}

/**
* samife_strlen - Get the length of a string.
*
* @s: Pointer to the string
* Return: The length of the string
*/
int samife_strlen(char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}


/**
* samife_putchar - Write a character to stdout.
*
* @c: The character to print
* Return: On success 1. On error, -1 is returned,
* and errno is set appropriately.
*/
int samife_putchar(char c)
{
	return (write(1, &c, 1));
}

/**
*print_string- Print a string.
*
* @str: Pointer to the string
*/

void print_string(char *str)
{
	int i = 0;

	while (str[i])
	{
		samife_putchar(str[i]);
		i++;
	}
}
