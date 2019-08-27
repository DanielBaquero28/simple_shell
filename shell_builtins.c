#include "shell.h"

/**
 * execute_line - Executes the command or builtin with its corresponding arguments
 * @args: Arguments that will be recieved.
 * Return: Launch the new process.
 */

int execute_line(char **args)
{
  int i;
  char *str;

  builtins_t built_ins[] = {
    {"env", hsh_env},
    {"help", hsh_help},
    {"exit", hsh_exit},
    {NULL, NULL}
  };
  if (args[0] == NULL)
    {
      return (1);
    }
  i = 0;
  while (built_ins[i].s != NULL)
    {
      str = built_ins[i].s;
      if (_strcmp(args[0], str) == 0)
	{
	  return(built_ins[i].f());
	}
      i++;
    }
  return(launch_pid(args));
}

/**
 * hsh_env - Prints the environment variable.
 * Return: 1 if successful.
 **/

int hsh_env(void)
{
  int i;
  char *env = *environ;
  i = 0;
  while(env != '\0')
    {
      _puts(env);
      _puts("\n");
      env = environ[i];
      i++;
    }
  free(env);
  return(1);
}

/**
 * hsh_help - Shows help instructions for the command entered.
 * @args: Arguments that recieves.
 * Return: 0 if successful
 **/

int hsh_help(void)
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

/**
 * hsh_exit - Exits the shell
 * @args: Arguments that revieves.
 * Return: 0
 **/

int hsh_exit(char **args)
{
/*  int status;*/
  int i = 0;
/*if(args[1] != NULL)
    {
      status = _atoi(args[1]);
      printf("%d", status);
      if (status >= 0)
	exit(status);
    }*/
  if (args != NULL)
  {
	 if (!args[i])
	 {
		  while(args[i])
		  {
			  free(args[i]);
			  i++;
		  }
	 }
	  free(args);
  }
  exit(0);
}
