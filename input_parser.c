#include "shell.h"

/**
 * parse_input - Tokenizes a string into an array of arguments.
 * @input: The input string to be parsed.
 * @parsed_args: An array of pointers to store the parsed arguments.
 * @parsed_arg_count: A pointer to an integer to store
 * the number of parsed arguments.
 *
 * This function tokenizes the input string based on spaces and stores the
 * resulting tokens in the parsed_args array. It also updates parsed_arg_count
 * with the number of parsed arguments.
 */
void parse_input(char *input, char *parsed_args[], int *parsed_arg_count)
{
	char *token = strtok(input, " ");

	while (token != NULL && *parsed_arg_count < MAX_COMMAND_LEN - 1)
	{
		parsed_args[(*parsed_arg_count)++] = token;
		token = strtok(NULL, " ");
	}
	parsed_args[*parsed_arg_count] = NULL;
}


