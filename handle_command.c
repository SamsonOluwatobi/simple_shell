#include "shell.h"

/**
 * handle_external_command - Execute an external command
 * @input: The command to execute
 * @executable_directory: The directory where the executable may be located
 *
 * This function takes a user-provided input string,
 * checks if it corresponds to an external command,
 * and then executes it. If the command is found in the "/bin/"
 * directory or in the specified `executable_directory`,
 * it is executed with any provided arguments.
 */
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
