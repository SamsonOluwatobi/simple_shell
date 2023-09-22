#include "shell.h"

void display_prompt(void)
{
	if (isatty(0) == 1)
	{
		write(1, "samife$ ", 8);
	}
}

void exit_shell(int val, char *ptr)
{
	free(ptr);
	exit(val);
}

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
