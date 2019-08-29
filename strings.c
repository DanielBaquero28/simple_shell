#include "shell.h"


/**
 * _strlen - Finds the length of a string
 * @s: The pointer from which the length of the string is found.
 * Return: Nothing
**/

int _strlen(char *s)
{
int len;

for (len = 0; s[len]; len++)
;
return (len);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropiately.
**/

int _putchar(char c)
{
return (write(1, &c, 1));
}

/**
 * _puts - Prints a string without format.
 * @str: String that will be printed.
 * Return: Nothing
 */
void _puts(char *str)
{
int i;

for (i = 0; str[i]; i++)
{
if (str[i] == '\0')
break;
_putchar(str[i]);
}
}

/**
 * _strcmp - Compares two strings
 * @str1: String to be compared from.
 * @str2: String to be compared with.
 * Return: The comparison in integers.
 **/

int _strcmp(char *str1, char *str2)
{
int i;

i = 0;
while (str1[i] == str2[i])
{
if (str1[i] == '\0')
return (0);
i++;
}
return (str1[i] - str2[i]);
}
