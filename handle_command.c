#include "shell.h"

void handle_external_command(char *input, char *executable_directory)
{
		char *args[MAX_COMMAND_LEN];

		int arg_count = 0;

		if (_strncmp(input, "/bin/", 5) == 0)
		{
			parse_input(input, args, &arg_count);
			execute_command(args, "");
		}
		else if (is_executable_in_directory(executable_directory, input))
		{
			parse_input(input, args, &arg_count);
			execute_command(args, executable_directory);
		}
		else
		{
			parse_input(input, args, &arg_count);
			execute_command(args, executable_directory);
		}
}

/**
* handle_builtin_command - Handle built-in commands
* @input: User input string
*/
void handle_builtin_command(char *input)
{
	input[_strcspn(input, "\n")] = '\0';
	if (_strcmp(input, "ls") == 0)
	{
		execute_ls();
	}
	else
	{
		perror("Unknown built-in command");
	}
}
