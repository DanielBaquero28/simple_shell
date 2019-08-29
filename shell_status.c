#include "shell.h"

/**
 * shell_status - Looks if the arguments are executable.
 * @args: Arguments (Array of pointers).
 * @paths: Array of paths where the argument can be found.
 * @env: Environmental variable.
 * @input: Line that is entered.
 * Return: Launches a new process.
**/

int shell_status(char **args, char **paths, char **env, char *input)
{
int flag = 0;

if (args[0] == NULL)
return (1);
flag = shell_builtins(args);
if (flag)
return (flag);
if ((args[0][0] != '/') && (shell_path(args, paths, env)))
return (1);
return (launch_pid(args, env, input, paths));
}


/**
 * shell_builtins - Finds each argument with its builtin.
 * @args: Arguments that receives.
 * Return: -1, 1 or 0, depending if it it or not or if it executes
 * the exit builtin.
**/

int shell_builtins(char **args)
{
if (_strcmp(args[0], "exit") == 0)
return (-1);
if (_strcmp(args[0], "env") == 0)
{
puts_args(environ);
return (1);
}
if (_strcmp(args[0], "help") == 0)
{
_puts("This is Daniel's and Vivi's hsh\n");
_puts("Type builtins name and hit enter\n");
_puts("These are the builtins we offer:\n");
_puts("\t1. cd\n");
_puts("\t2. env\n");
_puts("\t3. help\n");
_puts("\t4. exit\n");
return (1);
}
return (0);
}

/**
 * puts_args - Prints the output of the builtin requested.
 * @args: Arguments that are receives.
 * Return: Nothing
**/

void puts_args(char **args)
{
int i;

for (i = 0; args[i] != NULL; i++)
{
write(STDOUT_FILENO, args[i], _strlen(args[i]));
write(STDOUT_FILENO, "\n", 1);
}
}
