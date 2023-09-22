#include "shell.h"
/**
 * display_prompt - Display a prompt if running interactively.
 */
void display_prompt(void)
{
	if (isatty(0) == 1)
	{
		write(1, "samife$ ", 8);
	}
}
/**
 * exit_shell - Clean up and exit the shell.
 * @val: The exit value.
 * @ptr: Pointer to memory to free.
 */
void exit_shell(int val, char *ptr)
{
	free(ptr);
	exit(val);
}
/**
 * space - Check if a string consists of only spaces.
 * @arr: The input string.
 *
 * Return: 1 if the string consists of only spaces, 0 otherwise.
 */
int space(char *arr)
{
	unsigned int j;

	for (j = 0; j < strlen(arr) - 1; j++)
	{
		if (arr[j] != ' ')
		{
			return (0);
		}
	}
	return (1);
}
/**
 * environ - Print the environment variables.
 * @env: The array of environment variables.
 */
void environ(char **env)
{
	unsigned int j;

	size_t len;

	j = 0;
	while (env[j] != NULL)
	{
		len = 0;
		while (env[j][len] != '\0')
		{
			len++;
		}
		write(1, env[j], len);
		write(1, "\n", 1);
		j++;
	}
}
