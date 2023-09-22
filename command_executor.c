#include "shell.h"
/**
 * command_exec - Execute a command by searching the PATH.
 * @str: The command and arguments as an array of strings.
 *
 * Return: 1 if the command was executed successfully, 0 otherwise.
 */
int command_exec(char **str)
{
	char *PathToExec, *c, *buff;
	static char path_buf[1024], array[1000];
	unsigned int i = 0;

	if (access(*str, X_OK) == 0)
		return (1);
	PathToExec = getenv("PATH");
	if (PathToExec == NULL)
		return (0);
	strcpy(path_buf, PathToExec);
	c = strtok(path_buf, ":");
	while (c != NULL)
	{
		buff = malloc(strlen(c) + strlen("/") + strlen(*str) + 1);
		if (buff == NULL)
		{
			perror(*str);
			free(buff);
			return (0);
		}
		strcpy(buff, c);
		strcat(buff, "/");
		strcat(buff, *str);
		if (access(buff, X_OK) == 0)
		{
			while (i < strlen(buff))
			{
				array[i] = buff[i];
				i++;
			}
			array[i] = '\0';
			free(buff);
			*str = array;
			return (1);
		}
		free(buff);
		c = strtok(NULL, ":");
	}
	perror(*str);
	return (0);
}
