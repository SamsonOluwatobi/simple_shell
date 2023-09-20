#include "shell.h"

/**
 * _strcspn - Calculate the length of the initial segment of str
 * that consists of characters not in reject.
 * @str: The string to search.
 * @reject: The characters to exclude from the count.
 *
 * Return: The length of the initial segment of str that does not contain
 * any characters from reject.
 */
size_t _strcspn(const char *str, const char *reject)
{
	const char *s;
	const char *r;

	for (s = str; *s; s++)
	{
		for (r = reject; *r; r++)
		{
			if (*s == *r)
			{
				return (s - str);
			}
		}
	}

	return (s - str);
}

/**
 * _strcmp - Compare two strings character by character.
 * @str1: The first string to compare.
 * @str2: The second string to compare.
 *
 * Return: An integer less than, equal to, or greater than zero if str1
 * is found to be less than, equal to, or greater than str2, respectively.
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

/**
 * _strlen - Calculate the length of a string.
 * @str: The string to calculate the length of.
 *
 * Return: The length of the string.
 */
size_t _strlen(const char *str)
{
	const char *s = str;

	while (*s)
	{
		s++;
	}
	return (s - str);
}

/**
 * environment - Print environment variables.
 * @env: The array of environment variables to print.
 */
void environment(char **env)
{
	unsigned int i = 0;

	while (env[i] != NULL)
	{
		size_t len = _strlen(env[i]);

		if (write(STDOUT_FILENO, env[i], len) == -1 ||
		write(STDOUT_FILENO, "\n", 1) == -1)
		{
			perror("write");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}


