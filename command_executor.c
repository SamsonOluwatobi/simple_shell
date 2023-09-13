#include "shell.h"
/**
* execute_command - Execute a command with arguments
* @exec_args: Array of command arguments
* @exec_dir: Execution directory
*
* Description: This function forks a child process to execute a command
* and waits for the child process to complete.
*/
void execute_command(char *exec_args[], char *exec_dir)
{
	int status, i;
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error:");
		exit(1);
	}
	if (child_pid == 0)
	{
		int dev_null = open("/dev/null", O_WRONLY);
		char exec_path[MAX_PATH_LEN];
		int exec_path_len = 0;

		_dup2(dev_null, STDIN_FILENO);
		_dup2(STDOUT_FILENO, STDERR_FILENO);
		while (exec_dir[exec_path_len] != '\0')
			exec_path_len++;
		exec_path[0] = '\0';
		for (i = 0; i < exec_path_len && i < MAX_PATH_LEN - 1; i++)
			exec_path[i] = exec_dir[i];

		if (exec_path_len < MAX_PATH_LEN - 1)
		{
			exec_path[exec_path_len] = '/';
			exec_path_len++;
		}
		for (i = 0; exec_args[0][i] != '\0' && exec_path_len <
			MAX_PATH_LEN - 1; i++, exec_path_len++)
			exec_path[exec_path_len] = exec_args[0][i];

		exec_path[exec_path_len] = '\0';
		if (execve(exec_path, exec_args, NULL) == -1)
			error_command(exec_args);
	}
	else
	{
		wait(&status);
	}
}
