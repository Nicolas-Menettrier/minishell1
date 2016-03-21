/*
** path.c for path in /home/menet/Modules/UnixSystemProgramming/PSU_2015_minishell1
**
** Made by menett_a
** Login   <menett_a@epitech.net>
**
** Started on  Fri Jan 22 15:42:16 2016 menett_a
** Last update Sun Jan 24 23:05:38 2016 menett_a
*/

#include <stdlib.h>
#include <unistd.h>
#include "proto_mini.h"

char	*copy_str(char *str, char *copy, int *j)
{
  int	k;

  k = 0;
  while (copy != NULL && copy[k] != '\0')
    {
      str[*j] = copy[k];
      *j = *j + 1;
      k = k + 1;
    }
  return (str);
}

char	**replace_this(char **env, char *path, char *replace, int *i)
{
  int	j;

  if ((env[*i] = malloc(sizeof(char)
		    * (my_strlen(path) + 1 + my_strlen(replace) + 1))) == NULL)
    exit(1);
  j = 0;
  env[*i] = copy_str(env[*i], path, &j);
  env[*i][j] = '=';
  j = j + 1;
  env[*i] = copy_str(env[*i], replace, &j);
  env[*i][j] = '\0';
  return (env);
}

char	**can_i_replace(char *path, char **env, char *replace)
{
  int	i;

  i = 0;
  while (env[i] != NULL && my_strcmp_equal(replace, env[i]) != 1)
    i = i + 1;
  if (env[i] != NULL)
    {
      env = replace_this(env, replace, path, &i);
      return (env);
    }
  else
    {
      env = stock_env(env, 1, replace, path);
      return (env);
    }
  return (0);
}
