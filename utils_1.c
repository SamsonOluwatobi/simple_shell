#include "shell.h"
/**
 * readInputLine - Reads a line from a file stream using _getline or getline.
 * @lineptr: Pointer to a buffer where the line will be stored.
 * @n: Pointer to the size of the buffer.
 * @stream: File stream to read from.
 *
 * Return: The number of characters read (including newline), or -1 on failure.
 */
ssize_t readInputLine(char **lineptr, size_t *n, FILE *stream)
{

#ifdef _GETLINE_IMPLEMENTED
	return (_getline(lineptr, n, stream));
#else
	return (getline(lineptr, n, stream));
#endif
}
/**
 * tokenizeString - Tokenizes a string using _strtok or strtok.
 * @str: The string to tokenize (or NULL to continue tokenization).
 * @delim: The delimiter characters.
 *
 * Return: A pointer to the next token found,
 * or NULL if no more tokens are found.
 */
char *tokenizeString(char *str, const char *delim)
{
#ifdef _STRTOK_IMPLEMENTED
	return (_strtok(str, delim));
#else
	return (strtok(str, delim));
#endif
}
