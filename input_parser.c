#include "shell.h"

void parse_input(char *input, char *parsed_args[], int *parsed_arg_count)
{
	char *token = _strtok(input, " ");

	while (token != NULL && *parsed_arg_count < MAX_COMMAND_LEN - 1)
	{
		parsed_args[(*parsed_arg_count)++] = token;
		token = _strtok(NULL, " ");
	}
	parsed_args[*parsed_arg_count] = NULL;
}


