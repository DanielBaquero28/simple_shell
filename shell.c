#include "shell.h"

/**
 * loop_cmd - Interprets the command line.
 * Return: Nothing
 **/

int execute_line();
int loop_cmd(void)
{
  char *line = NULL;
  char **args = NULL;
  int i = 0;
  while (1)
    {
	    i= 0;
	    _puts("$cisfun# ");
	    line = read_line();
	    args = parse_line(line);
	    free(line);
	    execute_line(args);
	    if(args != NULL)
	    {
	      while(args[i])
		{
		  free(args[i]);
		  i++;
		}
	    }
	    free(args);
    }
  return(0);
}
/**
 * main - Calls loop function and if succeeds it returns an EXIT_SUCCESS
 * @ac: Argument Count
 * @av: Argument Vector
 * Return: EXIT_SUCCESS if request is successful
 **/
int main(int ac, char **av)
{
  (void)ac;
  (void)av;

  loop_cmd();
  return EXIT_SUCCESS;
}
