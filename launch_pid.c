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
  int i;
  pid_t pid;
  int status;

  pid = fork();
  if (pid == 0)
    {
      if(execve(args[0], args, NULL) == -1)
	perror( "Error: ");
      else
	execve(args[0], args, environ);
    }
  else if (pid > 0)
    {
      wait(&status);
      for (i = 0; i < 64; i++)
	{
	  free(args[i]);
	}
    }
  else
    perror("Error. ");
  return (0);
}
