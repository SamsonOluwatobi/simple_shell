#include "shell.h"

#define INITIAL_BUFFER_SIZE 1024
#define BUFFER_INCREMENT 1024
/**
 * _getline - Reads a line from a file stream.
 * @lineptr: Pointer to the buffer storing the line.
 * @n: Pointer to the size of the buffer.
 * @stream: File stream to read from.
 *
 * This function reads a line from the specified
 * file stream and stores it in the
 * buffer pointed to by lineptr. The size of the buffer is updated dynamically.
 * Return: Number of characters read (including newline), or -1 on failure or
 * end of file.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t i = 0;
	int c;

	char *temp;

	if (*lineptr == NULL || *n == 0)
	{
		*n = INITIAL_BUFFER_SIZE;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}

	while ((c = _fgetc(stream)) != EOF && c != '\n')
	{
		if (i >= *n - 1)
		{
			*n += BUFFER_INCREMENT;
			temp = (char *)realloc(*lineptr, *n);

			if (temp == NULL)
				return (-1);
			*lineptr = temp;
		}

		(*lineptr)[i++] = c;
	}
	if (i == 0 && c == EOF)
		return (-1);

	(*lineptr)[i] = '\0';
	return (i);
}
/**
 * _fgetc - Reads a character from a file stream.
 * @stream: File stream to read from.
 *
 * This function reads a single character from the specified file stream.
 * Return: The character read as an integer, or EOF if an error occurs or
 * end of file is reached.
 */
int _fgetc(FILE *stream)
{
	unsigned char c;

	int bytesRead = read(fileno(stream), &c, 1);

	if (stream == NULL || (stream->_flags) == 0)
	{
		return (EOF);
	}

	if (bytesRead == 1)
	{
		return ((int)c);
	}
	else
	{
		return (EOF);
	}
}
