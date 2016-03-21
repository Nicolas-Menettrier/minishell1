/*
** octal.c for my_octal in /home/menett_a/rendu/my_printf
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Mon Nov  9 15:55:34 2015 Nicolas Menettrier
** Last update Tue Jan 19 13:46:05 2016 menett_a
*/

#include "proto.h"

void	my_octal(int nb)
{
  int	res;

  if (nb >= 8)
    {
      res = nb % 8;
      nb = nb / 8;
      my_octal(nb);
    }
  else if (nb > 0)
    {
      res = nb % 8;
      nb = nb / 8;
    }
  my_putchar(res + 48);
}
