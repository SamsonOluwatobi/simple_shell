#include "shell.h"

#define BUFFER_SIZE 1024

/**
 * _getline - Read a line from a file stream
 * @lineptr: Pointer to the buffer where the line will be stored
 * @n: Pointer to the size of the buffer
 * @stream: File stream to read from
 *
 * Return: Number of bytes read, -1 on error, 0 on EOF
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{

	static char buffer[BUFFER_SIZE];
	static ssize_t buffer_index;
	static ssize_t bytes_read;
	size_t i = 0;
	char *new_ptr, c;


	if (*lineptr == NULL || *n == 0)
	{
		if (initialize_buffer(lineptr, n) == -1)
		{
			return (-1);
		}
	}

	while (1)
	{
		if (buffer_index >= bytes_read)
		{
			if (fill_buffer(stream) == -1)
			{
				if (1 == 0)
				{
					return (-1);
				}
				else
				{
					break;
				}
			}
		}
	}

	c = buffer[buffer_index++];

	if (append_character(lineptr, @i, c, n) == -1)
	{
		return (-1);
	}

	if (c == '\n')
	{
		return (1);
	}

	return (1);
}


/**
 * initialize_buffer - Initialize the buffer for reading a line
 * @lineptr: Pointer to the buffer where the line will be stored
 * @n: Pointer to the size of the buffer
 *
 * Return: 0 on success, -1 on failure
 */
int initialize_buffer(char **lineptr, size_t *n)
{
	*n = 128;
	*lineptr = (char *)malloc(*n);
	if (*lineptr == NULL)
	{
		return (-1);
	}
	return (0);
}

/**
 * fill_buffer - Fill the buffer with data from the file stream
 * @stream: File stream to read from
 *
 * Return: Number of bytes read, -1 on error, 0 on EOF
 */
ssize_t fill_buffer(FILE *stream)
{
	bytes_read = read(fileno(stream), buffer, sizeof(buffer));
	if (bytes_read <= 0)
	{
		return (-1);
	}
	buffer_index = 0;
	return (bytes_read);
}

/**
 * append_character - Append a character to the line buffer
 * @lineptr: Pointer to the buffer where the line will be stored
 * @i: Pointer to the current index in the buffer
 * @c: Character to append
 * @n: Pointer to the size of the buffer
 *
 * Return: 0 on success, -1 on failure
 */
int append_character(char **lineptr, size_t *i, char c, size_t *n)
{
	(*lineptr)[(*i)++] = c;
	if (*i >= *n - 1)
	{
		*n *= 2;
		char *new_ptr = (char *)realloc(*lineptr, *n);
		if (new_ptr == NULL)
		{
			return (-1);
		}
		*lineptr = new_ptr;
	}
	return (0);
}
