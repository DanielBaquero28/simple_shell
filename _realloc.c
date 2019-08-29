#include "shell.h"

/**
 * _realloc - Reallocates a memory block that was previously pointed to ptr.
 * @ptr: Pointer pointing to the memory previously allocated.
 * @old_size: The previous size of the memory block.
 * @new_size: The size of the new allocated memory block.
 * Return: Ptr pointing to new_size or NULL if unsuccesful.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *str;
unsigned int i;

if (ptr == NULL)
{
str = malloc(new_size);
return (str);
}
if (new_size == 0 && ptr != NULL)
{
free(ptr);
return (NULL);
}
if (new_size == old_size)
{
return (ptr);
}
str = malloc(new_size);
if (str == NULL)
return (NULL);
for (i = 0; i < old_size; i++)
str[i] = ((char *)ptr)[i];
free(ptr);
return (str);
}

