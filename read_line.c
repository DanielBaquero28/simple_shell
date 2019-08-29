#include "shell.h"

/**
 * read_line - Reads the input of the command taking into account it's path
 * to see if it's an environmental variable.
 * @path: Path where the command is located.
 * Return: Returns the line read (Basic interpretation)
**/

char *read_line(char **path)
{
char *line_read = NULL;
size_t buffersize = 0;
int flag;

flag = getline(&line_read, &buffersize, stdin);
if (flag == EOF)
{
free(line_read);
free(path);
exit(0);
}
line_read[flag - 1] = '\0';
return (line_read);
}
