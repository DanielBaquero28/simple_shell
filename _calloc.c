#include "shell.h"
#include <stdlib.h>
#include <string.h>
/**
 **_calloc - Assign space for an array of nmemb elements
 *@nmemb:This is character of elements to be allocated.
 *@size: This is the size of elements
 *Return: void
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *s;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	s = malloc(nmemb * size);
	if (s == NULL)
		return (NULL);
	for (i = 0; i < nmemb * size; i++)
		s[i] = 0;
	return (s);
}
