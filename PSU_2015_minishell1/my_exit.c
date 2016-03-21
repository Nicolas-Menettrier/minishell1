/*
** my_exit.c for my_exit in /home/menet/Modules/UnixSystemProgramming/PSU_2015_minishell1
**
** Made by menett_a
** Login   <menett_a@epitech.net>
**
** Started on  Sun Jan 24 23:28:43 2016 menett_a
** Last update Sun Jan 24 23:39:28 2016 menett_a
*/

#include <stdlib.h>
#include "proto_mini.h"

int	my_exit(int *ex, char **opt)
{
  if (opt[1] != NULL)
    {
      *ex = my_get_nbr(opt[1]);
      return (1);
    }
  return (1);
}
