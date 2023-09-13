#include "shell.h"

#define LS_COMMAND 1
#define CD_COMMAND 2


int get_command_id(const char *command)
{

	if (_strcmp(command, "ls") == 0)
	{
		return (LS_COMMAND);
	}
	else if (_strcmp(command, "cd") == 0)
	{
		return (CD_COMMAND);
	}
	return (0);
}


int is_builtin_command(char *command)
{

	int command_id = get_command_id(command);

	return (command_id != 0);
}

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

void execute_cd(void)
{
}
