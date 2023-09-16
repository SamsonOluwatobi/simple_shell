#include "shell.h"

/**
 * _dup2 - Duplicates a file descriptor
 * @oldfd: The old file descriptor to duplicate
 * @newfd: The new file descriptor to duplicate to
 *
 * Return: The new file descriptor, or -1 on failure
 */
int _dup2(int oldfd, int newfd)
{
	int result;

	if (oldfd == newfd)
	{
		return (newfd);
	}

	result = open("/dev/null", O_WRONLY);

	if (result == -1)
	{
		perror("Error in my_dup2:");
	}
	else if (result != newfd)
	{
		close(result);
		result = (-1);
	}
	return (result);
}


/**
* is_executable_in_directory - Checks if
* a command is executable in a directory
* @command: The command to check
* @directory: The directory to search for the command
*
* Return: 1 if the command is executable, 0 otherwise
*/
int is_executable_in_directory(const char *command, const char *directory)
{
	char exec_path[MAX_PATH_LEN];

	struct stat st;
	int i = 0, j = 0;

	/* Initialize exec_path as an empty string */
	exec_path[0] = '\0';

	/* Copy the directory path character by character */
	while (directory[i] != '\0' && i < MAX_PATH_LEN - 1)
	{
		exec_path[i] = directory[i];
		i++;
	}

	/* Add a '/' character if there is space */
	if (i < MAX_PATH_LEN - 1)
	{
		exec_path[i] = '/';
		i++;
	}

	/* Copy the command character by character */
	while (command[j] != '\0' && i < MAX_PATH_LEN - 1)
	{
		exec_path[i] = command[j];
		i++;
		j++;
	}

	/* Null-terminate the resulting string */
	exec_path[i] = '\0';

	/* Check if the file exists and is executable */
	if (stat(exec_path, &st) == 0 && st.st_mode & S_IXUSR)
		return (1); /* File exists and is executable */

	return (0); /* File does not exist or is not executable */
}


/**
* _strncmp - Custom string comparison function
* @str1: First string
* @str2: Second string
*
* Return: 0 if strings are equal, non-zero otherwise
*/

int _strncmp(const char *str1, const char *str2, size_t n)
{
	while (n > 0)
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}

		if (*str1 == '\0')
		{
			return (0);
		}

		str1++;
		str2++;
		n--;
	}
	return (0);
}
