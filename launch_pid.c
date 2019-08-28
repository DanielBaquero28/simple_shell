#include "shell.h"

/**
 * launch_pid - Forks the calling process in order to create 
 * another PID (child). 
 * @args: Arguments that recieves.
 * Return: If succeded PID of the child process is returned to PPID 
 * and 0 is returned to the child. If failed -1 is returned to PPID. 
 */

extern char **environ;

int launch_pid(char **args)
{
  pid_t pid;
  int status;

  pid = fork();
  if (pid == 0)
    {
      if(execve(args[0], args, NULL) == -1)
	{
	  free(args[0]);
	  perror( "Error");
	}
    }
  else if (pid > 0)
    {
      wait(&status);
    }
  else
    perror("Error. ");
  return (0);
}
