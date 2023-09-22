#include "shell.h"

const char *start_delim(const char *d, char *start, const char *delim);

/**
 * __strtok - Custom implementation of _strtok function
 * @str: The string to tokenize
 * @delim: The delimiter characters
 *
 * Return: A pointer to the next token or NULL if no more tokens are found
 */
char *_strtok(char *str, const char *delim)
{
	static char *token_ptr;
	char *start = (str != NULL) ? str : token_ptr, *end;
	int is_delim = 0;
	const char *d = 0;

	if (start == NULL)
	{
		return (NULL);
	}
	start_delim(d, start, delim);
	if (*start == '\0')
	{
		token_ptr = NULL;
		return (NULL);
	}
	end = start;
	while (*end != '\0')
	{
		is_delim = 0;
		for (d = delim; *d != '\0'; d++)
		{
			if (*end == *d)
			{
				is_delim = 1;
				break;
			}
		}
		if (is_delim)
		{
			break;
		}
		end++;
	}
	if (*end != '\0')
	{
		*end = '\0';
		token_ptr = end + 1;
	}
	else
	{
		token_ptr = NULL;
	}
	return (start);
}


/**
 * start_delim - Helper function to skip leading delimiter characters
 * @d: A pointer to the current delimiter character
 * @start: The start position in the string
 * @delim: The delimiter characters
 *
 * Return: A pointer to the first non-delimiter character in the string
 */
const char *start_delim(const char *d, char *start, const char *delim)
{
	while (*start != '\0')
	{
		int is_delim = 0;

		for (d = delim; *d != '\0'; d++)
		{
			if (*start == *d)
			{
				is_delim = 1;
				break;
			}
		}
		if (!is_delim)
		{
			break;
		}
		start++;
	}
	return (start);
}
