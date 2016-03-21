/*
** my_put_unsigned_nb.c for unsigned nb in /home/menett_a/rendu/my_printf
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Wed Nov 11 12:29:53 2015 Nicolas Menettrier
** Last update Tue Jan 19 13:45:40 2016 menett_a
*/

#include "proto.h"

void		my_put_unsigned_nb(unsigned int nb)
{
  unsigned int	nbf;

  if (nb >= 10)
    {
      nbf = nb % 10;
      nb = nb / 10;
      my_put_unsigned_nb(nb);
      my_putchar(nbf + 48);
    }
  else
    my_putchar(nb + 48);
}
