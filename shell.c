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

  while (1)
    {
      _puts("$cisfun# ");
      line = read_line();
      args = parse_line(line);
      execute_line(args);
      free(line);
      free(args);
    }
  return (0);
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
