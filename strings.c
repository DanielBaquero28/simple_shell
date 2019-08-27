#include "shell.h"

/**
 * print_str - Prints a String as a system call.
 * @str: Pointer that holds the String that is printed.
 * Return: Nothing
 */
void print_str(char *str)
{
  int _strlen();
  write(STDOUT_FILENO, str, _strlen(str));
}

/**
 * _strlen - Finds the length of a string
 * @s: The pointer from which the length of the string is found.
 *
 * Return: Nothing
 */

int _strlen(char *s)
{
  int i;
  for (i = 0; s[i] != 0; i++)
    {

    }
  return (i);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropiately.
 */

int _putchar(char c)
{
  return (write(1, &c, 1));
}

/**
 *_puts - function that prints a strings
 * @str:  "I do not fear computers. I fear the lack of them - Isaac Asimov"
 * Return: Nothing
 */

void _puts(char *str)

{
  int i;

  for (i = 0; str[i] != '\0'; i++)
    {
      _putchar(str[i]);
    }
}

/**
 * _strcmp - Compares two strings
 * @s1: Pointer that links with a string
 * @s2: Pointer that links with a string
 *
 * Return: Nothing
 **/

int _strcmp(char *s1, char *s2)
{
  int i;
  i = 0;
  while (s1[i] != '\0')
    {
      if (s1[i] > s2[i])
	{
	  return (s1[i] - s2[i]);
	}
      if (s1[i] < s2[i])
	{
	  return (s1[i] - s2[i]);
	}
      i++;
    }
  return (0);
}
