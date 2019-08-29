#include "shell.h"

/**
 * launch_pid - Forks the calling process in order to create
 * another PID (child) for builtins.
 * @args: Arguments that recieves.
 * @env: Environment Variable.
 * @input: Pointer to the entered string.
 * @paths: Array of paths where builtin is found.
 * Return: If succeded PID of the child process is returned to PPID
 * and 0 is returned to the child. If failed -1 is returned to PPID.
**/

int launch_pid(char **args, char **env, char *input, char **paths)
{
int status = 1;
pid_t pid;

pid = fork();
if (pid == -1)
{
perror("Error");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
if (execve(args[0], args, env) == -1)
{
perror("Error");
free(input);
free(args);
free(paths);
exit(EXIT_FAILURE);
}
}
else
{
waitpid(pid, &status, WUNTRACED);
}
return (1);
}
