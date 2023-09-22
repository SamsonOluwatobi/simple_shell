#include "shell.h"




char **splstr(char *str, const char *delim)
{
	int i, wordCount;
	char **wordArray;
	char *token;
	char *copy;

	copy = malloc(samife_strlen(str) + 1);
	if (copy == NULL)
	{
		perror(get_environment("_"));
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';

	token = strtok(copy, delim);
	wordArray = malloc((sizeof(char *) * 2));
	wordArray[0] = samife_strdup(token);

	i = 1;
	wordCount = 3;
	while (token)
	{
		token = strtok(NULL, delim);
		wordArray = reallocate(wordArray, (sizeof(char *) * (wordCount - 1)),
		(sizeof(char *) * wordCount));
		wordArray[i] = samife_strdup(token);
		i++;
		wordCount++;
	}
	free(copy);
	return (wordArray);
}


void execute_command(char **argv)
{

	int childPid, status;

	if (!argv || !argv[0])
		return;
	childPid = fork();
	if (childPid == -1)
	{
		perror(get_environment("_"));
	}
	if (childPid == 0)
	{
		execve(argv[0], argv, environ);
			perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	wait(&status);
}



void *reallocate(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new;
	char *old;

	unsigned int i;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new = malloc(new_size);
	old = ptr;
	if (new == NULL)
		return (NULL);

	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			new[i] = old[i];
		free(ptr);
		for (i = old_size; i < new_size; i++)
			new[i] = '\0';
	}
	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			new[i] = old[i];
		free(ptr);
	}
	return (new);
}

void freeArray(char **arv)
{
	int i;

	for (i = 0; arv[i]; i++)
		free(arv[i]);
	free(arv);
}