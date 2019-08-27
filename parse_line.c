#include "shell.h"

/**
 * read_line - Reads the line input.
 * Return: The address of the first input character
 * where the input string will be stored.
 **/
char *read_line(void)
{

  char *lineptr = NULL;
  size_t bufsize = 0; /* Getline reallocates the buffer for us */
  if (getline(&lineptr, &bufsize, stdin) == -1)
    {
      free(lineptr);
      exit(-1);
    }
  return (lineptr);
}

/**
 * parse - Tokenizes a string input line with a delimiter
 * that separates the program from the arguments.
 * @buf: Line buffer of the standard input.
 * Return: Pointer to the first postion of an array of pointers.
 */

char **parse_line(char *lineptr)
{
  char **tokens = NULL;
  char *len = NULL;
  int i = 0, size = 64; /* Changed data type from size_t to int *//* Changed size from 3 to 64 */
  unsigned int j;
  if (lineptr == NULL)
    return (NULL);

  tokens = calloc(sizeof(char*), size); /* Changed size and char with asterisk.*/
  if (tokens == NULL)
    {
      perror("Allocation Error!"); /* Changed to perror to assign error accordingly */
      return (NULL); /* Thinking on changing return to EXIT_FAILURE */
    }
  len = strtok(lineptr, DELIMITER);
  while (len != NULL)
    {
	    tokens[i] = malloc(sizeof(char) * (strlen(len) + 1));
      if (!tokens[i])
	{
	  perror("Allocation Error!");
	  return (NULL);
	}
      for (j = 0; j < strlen(len); j++)
	tokens[i][j] = len[j];
      tokens[i][j] = '\0';
      len = strtok(NULL, DELIMITER);
      i++;
    }
  tokens[i] = NULL;
  return (tokens);
}
