/*
** setenv.c for setenv in /home/menet/Modules/UnixSystemProgramming/PSU_2015_minishell1
**
** Made by menett_a
** Login   <menett_a@epitech.net>
**
** Started on  Fri Jan 22 20:25:05 2016 menett_a
** Last update Sun Jan 24 22:22:50 2016 menett_a
*/

#include <unistd.h>
#include <stdlib.h>
#include "proto_mini.h"

int	my_unsetenv(char **opt, char ***env)
{
  char	*delete;

  if (opt[1] != NULL)
    {
      delete = opt[1];
      *env = can_i_remove(*env, delete);
    }
  else
    my_printf("Usage : unsetenv NAME\n");
  return (1);
}

int	my_setenv(char **opt, char ***env)
{
  char	*path;
  char	*str;

  if (opt[1] != NULL)
    {
      str = opt[1];
      path = opt[2];
      *env = can_i_replace(path, *env, str);
    }
  else
    my_printf("Usage : setenv NAME [opt]\n");
  return (1);
}
