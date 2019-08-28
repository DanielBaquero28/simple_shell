#include "shell.h"

/**
* _atoi - Converts a string into a integer.
* @line: Pointer to string.
* Return: Number that we changed into or -1 if failed.
*/

int _atoi(char *line)
{
	int size, number, exponent, i;

	size = _strlen(line);
	exponent = 1;

	for (i = 1; i < size; i++)
		exponent *= 10;
	number = 0;
	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i] >= '0' && line[i] <= '9')
			number += (line[i] - '0') * exponent;
		else
		{
			perror("Error: Failed to interpret\n");
			return (-1);
		}
		exponent /= 10;
	}
	return (number);
}
