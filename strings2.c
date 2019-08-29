#include "shell.h"

/**
 * _strcpy - Copies a string pointed to src
 * @dest: Pointer
 * @src: Pointer
 *
 * Return: Nothing
 **/
char *_strcpy(char *dest, char *src)
{
int i;

for (i = 0; src[i]; i++)
dest[i] = src[i];
dest[i] = '\0';
return (dest);
}

/**
 * _strcat - Concatenates two string in the array
 * @dest: Functions for concatenate two strings.
 * @src: Character to put in array.
 * Return: Pointer type chars.
**/

char *_strcat(char *dest, char *src)
{
int sz;
int i;

for (sz = 0; dest[sz]; sz++)
;
for (i = 0; src[i]; i++)
{
dest[sz + i] = src[i];
}
dest[sz + i] = '\0';
return (dest);
}

/**
 * _strdup - Allocates a copy a str.
 * @str: String to be duplicated.
 * Return: New string.
**/

char *_strdup(char *str)
{
unsigned int i;
char *s;

if (str == NULL)
{
return (NULL);
}
s = malloc(_strlen(str) + 1);
if (s == NULL)
{
return (NULL);
}
for (i = 0; str[i]; i++)
{
s[i] = str[i];
}
s[i] = '\0';
return (s);
}
