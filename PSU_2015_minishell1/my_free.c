/*
** my_free.c for free in /home/menet/Modules/UnixSystemProgramming/PSU_2015_minishell1
**
** Made by menett_a
** Login   <menett_a@epitech.net>
**
** Started on  Thu Jan 21 16:54:42 2016 menett_a
** Last update Thu Jan 21 16:55:35 2016 menett_a
*/

#include <stdlib.h>

void	my_free(char **str)
{
  int	i;

  i = 0;
  while (str[i] != NULL)
    {
      free(str[i]);
      i = i + 1;
    }
  free(str);
}
