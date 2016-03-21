/*
** my_putstr.c for my_putstr in /home/menett_a/rendu/Piscine_C_J04
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Thu Oct  1 18:54:43 2015 Nicolas Menettrier
** Last update Sat Jan 23 23:17:22 2016 menett_a
*/

#include "proto.h"

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str == 0)
    {
      my_putstr("(null)");
      return;
    }
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
