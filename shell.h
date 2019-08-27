#ifndef HEADER_FILE_SHELL
#define HEADER_FILE_SHELL
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <stddef.h>
#include <signal.h>
#define BUFFER_SIZE 1024
#define PROMPT "$cisfun#"
#define DELIMITER " \t\r\n\a"
extern char **environ;
/**
 * struct list_t - List of builtins
 * @s: Pointer to characters
 * @f: Pointer to matching function
 **/

typedef struct list_t{
  char *s;
  int (*f)();
}builtins_t;
/*  Builtin Functions */
int hsh_env(void);
int hsh_help(void);
int hsh_exit(char **args);
/* Shell Basic Interpretation */
int execute_lihe(char **args);
int launch_pid(char **args);
int loop_cmd(void);
char *read_line(void);
char **parse_line(char *lineptr);
/* String Manipulation */
void print_str(char *str);
int _strlen(char *s);
void _puts(char *str);
int _putchar(char c);
int _atoi(char *line);
int _strcmp(char *s1, char *s2);
#endif
