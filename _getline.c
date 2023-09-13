#include "shell.h"

#define BUFFER_SIZE 1024

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{

	static char buffer[BUFFER_SIZE];

	static ssize_t buffer_index;
	static ssize_t bytes_read;
	size_t i = 0;
    char *new_ptr, c;

	if (*lineptr == NULL || *n == 0)
    {
		*n = 128;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL) {
			return (-1);
		}
	}

	while (1)
    {
		if (buffer_index >= bytes_read)
        {
			bytes_read = read(fileno(stream), buffer, sizeof(buffer));
			if (bytes_read <= 0)
            {
				if (i == 0)
                {
					return (-1);
				} else
                {
					break;
				}
			}
			buffer_index = 0;
		}

		c = buffer[buffer_index++];

		(*lineptr)[i++] = c;
		if (c == '\n')
        {
			(*lineptr)[i] = '\0';
			return (i);
		}

		if (i >= *n - 1)
        {
			*n *= 2;
			new_ptr = (char *)realloc(*lineptr, *n);

			if (new_ptr == NULL)
            {
				return (-1);
			}
			*lineptr = new_ptr;
		}
	}

	(*lineptr)[i] = '\0';
	return (i);
}
