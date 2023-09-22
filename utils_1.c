#include "shell.h"

void (*checkBuiltIn(char **arv))(char **arv)
{
	int i, j;
	samife_buildin builtInCommands[] = {
		{"exit", exit_shell},
		{"env", print_environment},
		{"setenv", set_environment},
		{"unsetenv", unset_environment},
		{NULL, NULL}
	};

	for (i = 0; builtInCommands[i].name; i++)
	{
		j = 0;
		if (builtInCommands[i].name[j] == arv[0][j])
		{
			for (j = 0; arv[0][j]; j++)
			{
				if (builtInCommands[i].name[j] != arv[0][j])
					break;
			}
			if (!arv[0][j])
				return (builtInCommands[i].func);
		}
	}
	return (0);
}
