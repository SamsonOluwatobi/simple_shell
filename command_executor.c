#include "shell.h"
/**
* check_access - Checks if the file at the specified path is executable.
* @filename: The path to the file to be checked.
*
* Return: 1 if executable, 0 if not.
*/
int check_access(const char *filename)
{
	return (access(filename, X_OK) == 0);
}
/**
 * search_path_and_execute - Searches for
 * the executable in the PATH and executes it.
 * @command: The command to be executed (may be updated to the full path).
 *
 * Return: 1 if executable found and executed, 0 otherwise.
 */
int search_path_and_execute(char **command)
{
	char *path = getenv("PATH"), *token;

	char path_buffer[1024], *executable_path;

	if (path == NULL)
		return (0);

	strcpy(path_buffer, path);
	token = tokenizeString(path_buffer, ":");

	while (token != NULL)
	{
		executable_path = malloc(strlen(token) +
		strlen("/") + strlen(*command) + 1);

		if (executable_path == NULL)
		{
			perror(*command);
			return (0);
		}

		strcpy(executable_path, token);
		strcat(executable_path, "/");
		strcat(executable_path, *command);

		if (check_access(executable_path))
		{
			strcpy(*command, executable_path);
			free(executable_path);
			return (1);
		}

		free(executable_path);
		token = tokenizeString(NULL, ":");
	}

	perror(*command);
	return (0);
}
/**
* command_exec - Execute a command by searching the PATH.
* @str: The command and arguments as an array of strings.
*
* Return: 1 if the command was executed successfully, 0 otherwise.
*/
int command_exec(char **str)
{
	if (str == NULL || *str == NULL)
		return (0);

	if (check_access(*str))
		return (1);

	if (search_path_and_execute(str))
		return (1);

	return (0);
}
