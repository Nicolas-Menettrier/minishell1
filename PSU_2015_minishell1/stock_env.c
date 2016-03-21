/*
** stock_env.c for env in /home/menet/Modules/UnixSystemProgramming/PSU_2015_minishell1
**
** Made by menett_a
** Login   <menett_a@epitech.net>
**
** Started on  Fri Jan 22 18:21:02 2016 menett_a
** Last update Sat Jan 23 23:40:58 2016 menett_a
*/

#include <stdlib.h>
#include <unistd.h>
#include "proto_mini.h"

char	**norme_stock(char **env, char **copy_env)
{
  int	i;
  int	j;

  i = 0;
  while (env[i] != NULL)
    {
      j = 0;
      while (env[i][j] != '\0')
	j = j + 1;
      if ((copy_env[i] = malloc(sizeof(char) * (j + 1))) == NULL)
	exit(1);
      j = 0;
      while (env[i][j] != '\0')
	{
	  copy_env[i][j] = env[i][j];
	  j = j + 1;
	}
      copy_env[i][j] = '\0';
      i = i + 1;
    }
  return (copy_env);
}

char	**copy_line(char **copy_env, int i, char *str, char *path)
{
  int	j;
  int	k;

  j = 0;
  k = 0;
  while (str != NULL && str[j] != '\0')
    {
      copy_env[i][k] = str[j];
      k = k + 1;
      j = j + 1;
    }
  j = 0;
  copy_env[i][k] = '=';
  k = k + 1;
  while (path != NULL && path[j] != '\0')
    {
      copy_env[i][k] = path[j];
      k = k + 1;
      j = j + 1;
    }
  copy_env[i][k] = '\0';
  return (copy_env);
}

char	**new_line(char *str, char **copy_env, char *path, int i)
{
  int	j;
  int	k;

  j = 0;
  k = 0;
  while (str != NULL && str[j] != '\0')
    j = j + 1;
  while (path != NULL && path[k] != '\0')
    k = k + 1;
  if ((copy_env[i] = malloc(sizeof(char) * (j + k + 2))) == NULL)
    exit(1);
  copy_env = copy_line(copy_env, i, str, path);
  j = 0;
  k = 0;
  return (copy_env);
}

char	**stock_env(char **env, int size, char *str, char *path)
{
  char	**copy_env;
  int	i;

  i = 0;
  while (env[i] != NULL)
    i = i + 1;
  if ((copy_env = malloc(sizeof(char *) * (i + size + 1))) == NULL)
    exit(1);
  copy_env[i + size] = NULL;
  copy_env = norme_stock(env, copy_env);
  if (str != NULL)
    copy_env = new_line(str, copy_env, path, i + size - 1);
  return (copy_env);
}
