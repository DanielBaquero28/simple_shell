#include "shell.h"

/**
 * main - Calls the loop_cmd function, where it interprets completely the command line.
 * @ac: Argument Count (number)
 * @av: Argument Vector (Multidimensional Array)
 * env: Environment Variable.
 * Return: 0 when successful
**/

int main(int ac, char **av, char **env)
{
(void)ac;
(void)av;

loop_cmd(env);

return (0);
}

/**
 * loop_cmd - Interprets the complete input command line.
 * @env: Environment Variable
 * Return: Nothing.
**/

void loop_cmd(char **env)
{
int status;
char *input, *delim, *path_line, **args, **path;

if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "$ ", 2);
path_line = get_env(env, "PATH");
delim = ":";
path = parse_line(path_line, delim);
delim = " \t\r\a\n";
do {
input = read_line(path);
args = parse_line(input, delim);
status = shell_status(args, path, env, input);
free(input);
free(args);
if (status == -1)
{
free(path);
exit(EXIT_SUCCESS);
}
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "$ ", 2);
} while (status);
free(path);
}

