#include "shell.h"

/**
 * parse_line - Tokenizes a string input line with a delimiter
 * that separates them in arguments gruoped in an array of pointers..
 * @input: String that is entered as input.
 * @delim: Delimiter that determines where the tokenization is made.
 * Return: Pointer to the first position of an array of pointers.
**/

char **parse_line(char *input, char *delim)
{
int i = 0;
int buffersize = 1024, buffersize_real = 0;
char **args;

args = malloc(buffersize * sizeof(char *));

if (!args)
{
perror("Error");
exit(EXIT_FAILURE);
}
args[i] = strtok(input, delim);
i++;
while (1)
{
args[i] = strtok(NULL, delim);
if (args[i] == NULL)
{
args[i + 1] = NULL;
return (args);
}
if (i >= buffersize)
{
buffersize_real = buffersize;
buffersize += BUFFER_SIZE;
args = _realloc(args, buffersize_real, buffersize);
if (!args)
{
perror("Error");
exit(EXIT_FAILURE);
}
}
i++;
}
}

