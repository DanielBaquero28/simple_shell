#ifndef HEADER_SHELL
#define HEADER_SHELL
/* Declarations */
#define BUFFER_SIZE 1024
extern char **environ;
/* Libraries */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
/* String Manipulation */
char *_strdup(char *str);
void _puts(char *str);
int _putchar(char c);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *str1, char *str2);
int _strlen(char *str1);
/* Basic Loop Interpretation */
void puts_args(char **args);
void loop_cmd(char **env);
char *read_line(char **path);
char **parse_line(char *input, char *delim);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
/* PATH */
int launch_pid(char **args, char **env, char *input, char **paths);
int shell_status(char **args, char **paths, char **env, char *input);
char *get_env(char **env, const char *name);
int shell_path(char **args, char **paths, char **env);
int shell_builtins(char **args);
#endif
