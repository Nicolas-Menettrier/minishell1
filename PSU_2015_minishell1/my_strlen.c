/*
** my_strlen.c for my_strlen in /home/menet/Modules/UnixSystemProgramming/PSU_2015_minishell1/test_env
**
** Made by menett_a
** Login   <menett_a@epitech.net>
**
** Started on  Thu Jan 21 13:32:22 2016 menett_a
** Last update Sat Jan 23 23:36:47 2016 menett_a
*/

#include <stdlib.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str != NULL && str[i] != '\0')
    i = i + 1;
  return (i);
}
