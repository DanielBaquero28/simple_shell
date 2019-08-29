#include "shell.h"

/**
 * args_cpy - Makes copy of the arguments so we can see if they are builtins.
 * @path: Path of the command (Where it is located).
 * @args: Arguments to be copied.
 * Return: New array of pointers with arguments of args.
**/

char **args_cpy(char *path, char **args)
{
int i, j;
char **new_args;

for (i = 0; args[i]; i++)
;
new_args = malloc(sizeof(char *) * (i + 1));
if (!new_args)
{
perror("Error");
exit(EXIT_FAILURE);
}
for (j = 0; j < i; j++)
new_args[j] = 0;
new_args[0] = _strdup(path);
j = 1;
while (args[j])
{
if (args[j])
{
new_args[j] = _strdup(args[j]);
}
j++;
}
new_args[j] = NULL;
return (new_args);
}

/**
 * launch_pid_exe - Forks the calling process in order to create
 * another PID (child).
 * @new_args: Arguments that recieves which is a copy of
 * the original set of arguments.
 * @env: Environment Variable
 * Return: If succeded PID of the child process is returned to PPID
 * and 0 is returned to the child. If failed -1 is returned to PPID.
**/

int launch_pid_exe(char **new_args, char **env)
{
int status = 1;
pid_t pid;

pid = fork();
if (pid == -1)
{
perror("Error");
}
else if (pid == 0)
{
if (execve(new_args[0], new_args, env) == -1)
{
perror("Error");
exit(EXIT_FAILURE);
}
}
else
{
waitpid(pid, &status, WUNTRACED);
}
return (1);
}


/**
 * shell_path - Indicates if the the token is a file or a directory.
 * @args: Arguments that are received.
 * @paths: Array of paths to match where the command is found.
 * @env: Environment variable.
 * Return: 0 if successful else 1.
**/

int shell_path(char **args, char **paths, char **env)
{
int i, j;
char *path;
char **new_args;
/* Declared in the <sys/stat.h> header */
struct stat mode_t;

for (i = 0; paths[i]; i++)
{
path = malloc(1024 * sizeof(char));
_strcpy(path, paths[i]);
_strcat(path, "/");
_strcat(path, args[0]);
if (stat(path, &mode_t) == 0)
{
new_args = args_cpy(path, args);
launch_pid_exe(new_args, env);
free(path);
j = 0;
if (new_args[j])
{
while (new_args[j])
{
free(new_args[j]);
j++;
}
}
free(new_args[j]);
free(new_args);
return (1);
}
free(path);
}
return (0);
}
