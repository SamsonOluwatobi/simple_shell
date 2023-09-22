#include "shell.h"
/**
 * main - Entry point for the simple shell program.
 * @argc: The number of command-line arguments (unused in this program).
 * @argv: An array of command-line argument strings (unused in this program).
 * @env: An array of environ variables.
 *
 * Return: 0 on success, non-zero on failure.
 */
int main(int argc, char **argv, char **env)
{
	int _gbyte, pid, x;
	size_t len = 0;
	char *arg[10], *arr = NULL;
	(void) argc, (void)argv;

	while (1)
	{
		display_prompt();
		_gbyte = _getline(&arr, &len, stdin);
		if (_gbyte == -1)
			checkgetline(arr);
		if (space(arr))
			continue;
		arg[0] = strtok(arr, " \n");
		if (strcmp(arg[0], "exit") == 0)
		{
			exit_shell(0, arr);
		}
		if (strcmp(arg[0], "env") == 0 || strcmp(arg[0], "printenv") == 0)
		{
			environ(env);
			continue;
		}
		x = 0;
		while (arg[x] != NULL)
		{
			x++;
			arg[x] = strtok(NULL, " \n");
		}
		if (command_exec(&arg[0]) == 1)
		{
			pid = fork();
			if (pid == 0)
				execve(arg[0], arg, NULL);
			else
				wait(NULL);
		}
	}
	return (0);
}

/**
 * checkgetline - checks getline
 * @ptr: pointer to array.
 */
void checkgetline(char *ptr)
{
	write(0, "\n", 2);
	exit_shell(0, ptr);
}
