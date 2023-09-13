#include "shell.h"

const char *start_delim(const char *d, char *start, const char *delim);

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
