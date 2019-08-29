#include "shell.h"

/**
 * var_name - Finds variable name.
 * @var: Variable found in the haystack.
 * Return: Variable name.
**/

char *var_name(char *var)
{
  int i;
  char *v_name;

  v_name = malloc(1024);
  if (!v_name)
    {
      perror("Error");
      exit(EXIT_FAILURE);
    }
  for (i = 0; var[i] != '='; i++)
    v_name[i] = var[i];
  v_name[i] = '\0';
  return (v_name);
}

/**
 * _match - Matches a string with the variable name we are looking for.
 * @name: Name of the string.
 * @var: Variable name.
 * Return: 0 if failed or else 1 when suceeded.
 **/

int _match(const char *name, char *var)
{
  int i;

  for (i = 0; name[i] && var[i]; i++)
    {
      if (name[i] != var[i])
	return (0);
    }
  if (name[i] != var[i])
    return (0);
  return (1);
}

/**
 * contents_var - Prints contents of the variable.
 * @var: Variable name.
 * Return: Contents the variable name.
 **/

char *contents_var(char *var)
{
  int i;

  for (i = 0; var[i] != '='; i++)
    ;
  return (var + i + 1);
}

/**
 * get_env - Prints environment variable content.
 * @env: Environment variable.
 * @name: Name of the var.
 * Return: Contents of environment variable
 **/

char *get_env(char **env, const char *name)
{
  int i;
  char *v_name;

  for (i = 0; env[i]; i++)
    {
      v_name = var_name(env[i]);
      if (_match(name, v_name))
	{
	  free(v_name);
	  return (contents_var(env[i]));
	}
      free(v_name);
    }
  return (NULL);
}
