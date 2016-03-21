/*
** my_unsetenv.c for unsetenv in /home/menet/Modules/UnixSystemProgramming/PSU_2015_minishell1
**
** Made by menett_a
** Login   <menett_a@epitech.net>
**
** Started on  Sat Jan 23 23:50:11 2016 menett_a
** Last update Sun Jan 24 23:04:57 2016 menett_a
*/

#include <unistd.h>
#include <stdlib.h>
#include "proto_mini.h"

char	*copy_norm(char *env, char *copy_env)
{
  int	i;

  i = 0;
  while (env[i] != '\0')
    {
      copy_env[i] = env[i];
      i = i + 1;
    }
  copy_env[i] = '\0';
  return (copy_env);
}

char	**copy_env_unset(char **env, char **copy_env, int i)
{
  int	j;
  int	k;
  int	l;

  k = 0;
  j = 0;
  l = 0;
  while (env[l] != NULL)
    {
      if (l != i)
	{
	  k = 0;
	  while (env[l][k] != '\0')
	    k = k + 1;
	  if ((copy_env[j] = malloc(sizeof(char) * (k + 1))) == NULL)
	    exit(1);
	  copy_env[j] = copy_norm(env[l], copy_env[j]);
	  j = j + 1;
	}
      l = l + 1;
    }
  return (copy_env);
}

char	**my_unset(char **env, int i)
{
  int	j;
  char	**copy_env;

  j = 0;
  while (env[j] != NULL)
    j = j + 1;
  if ((copy_env = malloc(sizeof(char *) * j)) == NULL)
    exit(1);
  copy_env[j - 1] = NULL;
  copy_env = copy_env_unset(env, copy_env, i);
  my_free(env);
  return (copy_env);
}

char	**can_i_remove(char **env, char *delete)
{
  int	i;

  i = 0;
  while (env[i] != NULL && my_strcmp_equal(delete, env[i]) != 1)
    i = i + 1;
  if (env[i] != NULL)
    {
      env = my_unset(env, i);
      return (env);
    }
  else
    my_printf("cannot find %s\n", delete);
  return (env);
}
