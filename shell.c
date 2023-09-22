#include "shell.h"

/**
* handle_sigint - handles the SIGINT signal (Ctrl+C)
* @sig_num: the signal number
*/
void handle_sigint(int sig_num)
{
	if (sig_num == SIGINT)
	{
		print_string("\n#samife$ ");
	}
}

/**
* handle_eof - handles the End of File condition
* @len: the return value of the getline function
* @buff: the buffer
*/
void handle_eof(int len, char *buff)
{
	(void)buff;
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			print_string("\n");
			free(buff);
		}
		exit(0);
	}
}

/**
* check_terminal - checks if the program is running in a terminal
*/
void check_terminal(void)
{
	if (isatty(STDIN_FILENO))
		print_string("#samife$ ");
}

/**
* main - The Shell program
* Return: 0 on success
*/
int main(void)
{
	ssize_t len = 0;
	char *buff = NULL, *value, *pathname, **args;
	size_t size = 0;
	path_list *head = '\0';
	void (*func)(char **);

	signal(SIGINT, handle_sigint);
	while (len != EOF)
	{
		check_terminal();
		len = _getline(&buff, &size, stdin);
		handle_eof(len, buff);
		args = splstr(buff, " \n");
		if (!args || !args[0])
			execute_command(args);
		else
		{
			value = get_environment("PATH");
			head = createPathList(value);
			pathname = findPathname(args[0], head);
			func = checkBuiltIn(args);
			if (func)
			{
				free(buff);
				func(args);
			}
			else if (!pathname)
				execute_command(args);
			else if (pathname)
			{
				free(args[0]);
				args[0] = pathname;
				execute_command(args);
			}
		}
	}
	free_path_list(head);
	freeArray(args);
	free(buff);
	return (0);
}
