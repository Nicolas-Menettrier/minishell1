/*
1;2802;0c** my_test.c for test in /home/menet/Modules/UnixSystemProgramming/PSU_2015_minishell1
**
** Made by menett_a
** Login   <menett_a@epitech.net>
**
** Started on  Sun Jan 24 22:32:52 2016 menett_a
** Last update Sun Jan 24 22:55:13 2016 menett_a
*/

#include <stdlib.h>
#include "proto_mini.h"

int	my_test(char **env, char **opt, int *i)
{
  while (env[*i] != NULL && is_path(env[*i]) != 0)
    *i = *i + 1;
  if (is_path(env[*i]) != 0 && opt[0][0] != '/' && opt[0][0] != '.')
    return (-1);
  else if (my_strcmp_equal("PATH", env[*i]) == 1 && env[*i][5] == '\0')
    return (-1);
  return (0);
}
