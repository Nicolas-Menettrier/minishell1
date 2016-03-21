/*
** binaire.c for binaire.c in /home/menett_a/rendu/my_printf
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Wed Nov 11 14:59:41 2015 Nicolas Menettrier
** Last update Tue Jan 19 13:44:50 2016 menett_a
*/

#include "proto.h"

void	my_binary(int nb)
{
  int	res;

  if (nb >= 2)
    {
      res = nb % 2;
      nb = nb / 2;
      my_binary(nb);
    }
  else if (nb > 0)
    {
      res = nb % 2;
      nb = nb / 2;
    }
  my_putchar(res + 48);
}
