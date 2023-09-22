#ifndef samife_SHELL_H
#define samife_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

int samife_putchar(char c);

void print_string(char *str);

int samife_strlen(char *s);

char *samife_strdup(char *str);

char *concatenate_strings(char *name, char *sep, char *value);

char **splstr(char *str, const char *delim);

void execute_command(char **argv);

void *reallocate(void *ptr, unsigned int old_size, unsigned int new_size);


extern char **environ;

/**
* struct path_list - Linked list containing directories in PATH
* @dir: directory in PATH
* @next: pointer to next node
*/
typedef struct path_list
{
	char *dir;

	struct path_list *next;
} path_list;


char *get_environment(const char *name);

path_list *addNodeToEnd(path_list **head, char *str);

path_list *createPathList(char *path);

char *findPathname(char *filename, path_list *head);

/**
* struct samife_buildin - pointer to function
* with corresponding buildin command
* @name: buildin command
* @func: execute the buildin command
*/
typedef struct samife_buildin
{
	char *name;

	void (*func)(char **);
} samife_buildin;

void(*checkBuiltIn(char **arv))(char **arv);

int _fgetc(FILE *stream);

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

char *_strtok(char *str, const char *delim);

int convert_to_int(char *s);

void exit_shell(char **arv);

void print_environment(char **arv);

void set_environment(char **arv);

void unset_environment(char **arv);

void freeArray(char **arv);

void free_path_list(path_list *head);


#endif
