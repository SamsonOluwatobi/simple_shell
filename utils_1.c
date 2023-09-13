#include "shell.h"


size_t _strcspn(const char *str, const char *reject)
{
	const char *s;
	const char *r;

	for (s = str; *s; s++)
    {
		for (r = reject; *r; r++)
        {
			if (*s == *r)
            {
				return (s - str);
			}
		}
	}

	return (s - str);
}

int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

size_t _strlen(const char *str)
{
	const char *s = str;

	while (*s)
	{
		s++;
	}
	return (s - str);
}

void environment(char **env)
{
	unsigned int i = 0;

	while (env[i] != NULL)
	{
		size_t len = _strlen(env[i]);
		if (write(STDOUT_FILENO, env[i], len) == -1 ||
		write(STDOUT_FILENO, "\n", 1) == -1)
		{
			perror("write");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}


void error_command(char *exec_args[])
{
			char *command = exec_args[0];

			write(STDOUT_FILENO, "SAMIFE: ", 8);
			write(STDOUT_FILENO, command, _strlen(command));
			write(STDOUT_FILENO, ": command not found\n", 20);
			_exit(1);
}
