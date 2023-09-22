#include "shell.h"


/**
 * get_environment - gets the result of the environment variable
 * @name: name of the environment variable
 * Return: string result of the variable
 */
char *get_environment(const char *name)
{
	int a, b;
	char *result;

	if (!name)
		return (NULL);
	for (a = 0; environ[a]; a++)
	{
		b = 0;
		if (name[b] == environ[a][b])
		{
			while (name[b])
			{
				if (name[b] != environ[a][b])
					break;

				b++;
			}
			if (name[b] == '\0')
			{
				result = (environ[a] + b + 1);
				return (result);
			}
		}
	}
	return (0);
}


/**
 * addNodeToEnd - adds a new node at the end of a linked list
 * @head: pointer to pointer to the linked list
 * @str: pointer to string in previous first node
 * Return: address of the new element/node
 */

path_list *addNodeToEnd(path_list **head, char *str)
{

	path_list *tmp;
	path_list *new;

	new = malloc(sizeof(path_list));

	if (!new || !str)
	{
		return (NULL);
	}

	new->dir = str;

	new->next = '\0';
	if (!*head)
	{
		*head = new;
	}
	else
	{
		tmp = *head;

		while (tmp->next)
		{

			tmp = tmp->next;
		}

		tmp->next = new;
	}

	return (*head);
}


/**
 * createPathList - creates a linked list for path directories
 * @path: string of path result
 * Return: pointer to the created linked list
 */
path_list *createPathList(char *path)
{
	path_list *head = '\0';
	char *token;
	char *copiedPath = samife_strdup(path);

	token = strtok(copiedPath, ":");
	while (token)
	{
		head = addNodeToEnd(&head, token);
		token = strtok(NULL, ":");
	}

	return (head);
}

/**
 * findPathname - finds the pathname of a filename
 * @filename: name of file or command
 * @head: head of linked list of path directories
 * Return: pathname of filename or NULL if no match
 */
char *findPathname(char *filename, path_list *head)
{
	struct stat st;
	char *string;

	path_list *tmp = head;

	while (tmp)
	{

		string = concatenate_strings(tmp->dir, "/", filename);
		if (stat(string, &st) == 0)
		{
			return (string);
		}
		free(string);
		tmp = tmp->next;
	}

	return (NULL);
}

/**
 * free_path_list - frees a linked list
 *@head: pointer to the linked list
 */
void free_path_list(path_list *head)
{
	path_list *storage;

	while (head)
	{
		storage = head->next;
		free(head->dir);
		free(head);
		head = storage;
	}

}
