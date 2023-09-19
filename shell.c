#include "shell.h"

/**
 * main - Entry point for the simple shell program.
 * @argc: The number of command-line arguments (unused in this program).
 * @argv: An array of command-line argument strings (unused in this program).
 * @env: An array of environment variables.
 *
 * Return: 0 on success, non-zero on failure.
 */
int main(int argc, char **argv, char **env)
{
	char *executable_directory = "/usr/bin", *lineptr = NULL;
	size_t len = 0;
	int x = 0;
	(void)(argc);
	(void)(argv);

	while (1)
	{
		write(STDOUT_FILENO, "~/SAMIFE$: ) ", 11);
		if (getline(&lineptr, &len, stdin) == -1)
		{
			write(STDOUT_FILENO, "Exiting shell...\n", 18);
			break;
		}
		lineptr[_strcspn(lineptr, "\n")] = '\0';
		if (_strcmp(lineptr, "exit") == 0)
		{
			write(STDOUT_FILENO, "Exiting shell...\n", 18);
			break;
		}
		if ((_strcmp(lineptr, "env") == 0) || (_strcmp(lineptr, "printenv") == 0))
		{
			environment(env);
			execute_env(env);
		}
		if (is_builtin_command(lineptr))
		{
			handle_builtin_command(lineptr);
		}
		else if (access(lineptr, X_OK) == 0 || x == 0)
		{
			handle_external_command(lineptr, executable_directory);
		}
		else
		{
			perror("Error ");
		}
	}
	free(lineptr);
	return (0);
}
