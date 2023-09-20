#include "shell.h"

#define LS_COMMAND 1
#define CD_COMMAND 2

/**
 * get_command_id - Get the ID of a built-in command.
 * @command: The command to check.
 *
 * Return: The ID of the command or 0 if not found.
 */
int get_command_id(const char *command)
{

	if ((_strcmp(command, "ls") == 0))
	{
		return (LS_COMMAND);
	}
	return (0);
}

/**
 * is_builtin_command - Check if a command is a built-in command.
 * @command: The command to check.
 *
 * Return: 1 if it's a built-in command, 0 otherwise.
 */
int is_builtin_command(char *command)
{

	int command_id = get_command_id(command);

	return (command_id != 0);
}

/**
 * execute_ls - Execute the 'ls' command.
 */
void execute_ls(void)
{
pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		char *ls_args[] = {"ls", NULL};

		char *ls_env[] = {NULL};


		char *ls_path = "/bin/ls";


		if (execve(ls_path, ls_args, ls_env) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}

/**
 * execute_env - Execute the 'env' command.
 * @env: The environment variables.
 */
	void execute_env(char **env)
	{
		pid_t child_pid = fork();

		if (child_pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0)
		{
			char *env_args[] = {"env", NULL};


			execve("/usr/bin/env", env_args, env);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
	}

/**
 * execute_cd - Execute the 'cd' command.
 */
void execute_cd(void)
{
}
