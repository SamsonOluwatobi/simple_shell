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
#include <string.h>

void display_prompt(void);

int _fgetc(FILE *stream);

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void exit_shell(int val, char *ptr);

char *_strtok(char *str, const char *delim);
char *tokenizeString(char *str, const char *delim);
ssize_t readInputLine(char **lineptr, size_t *n, FILE *stream);
void checkgetline(char *ptr);
int space(char *arr);
void environ(char **env);
int command_exec(char **str);
int search_path_and_execute(char **command);
int check_access(const char *filename);

#endif
