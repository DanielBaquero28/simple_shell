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
* parse_line - Tokenizes a string input line with a delimiter.
* @lineptr: Line buffer of the standard input.
* Return: Pointer to the first postion of an array of pointers.
*/

char **parse_line(char *lineptr)
{
	char **tokens = NULL;
	char *len = NULL;
	int i = 0, size = 1024;
	unsigned int j;

	if (lineptr == NULL)
		return (NULL);
	tokens = _calloc(sizeof(char *), size + 1);
	if (tokens == NULL)
	{
		perror("Allocation Error!");
		return (NULL);
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
