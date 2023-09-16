#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <stddef.h>

#define MAX_COMMAND_LEN 100
#define MAX_PATH_LEN 100

void parse_input(char *input, char *parsed_args[], int *parsed_arg_count);

void execute_command(char *exec_args[], char *exec_dir);

int is_builtin_command(char *command);

void handle_external_command(char *input, char *executable_directory);

void handle_builtin_command(char *input);

void execute_ls(void);
void execute_cd(void);
void execute_env(char **env);
int _dup2(int oldfd, int newfd);
int _strncmp(const char *str1, const char *str2, size_t n);
int is_executable_in_directory(const char *command, const char *directory);
size_t _strcspn(const char *str, const char *reject);
int _strcmp(const char *str1, const char *str2);
size_t _strlen(const char *str);
void environment(char **env);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void error_command(char *exec_args[]);
char *_strtok(char *str, const char *delim);
int append_character(char **lineptr, size_t *i, char c, size_t *n)
ssize_t fill_buffer(FILE *stream)
int initialize_buffer(char **lineptr, size_t *n)
#endif
