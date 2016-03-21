/*
** hexa_capitalize.c for hexa_capitalize in /home/menett_a/rendu/my_printf
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Wed Nov 11 17:28:50 2015 Nicolas Menettrier
** Last update Tue Jan 19 13:45:05 2016 menett_a
*/

#include "proto.h"

void	my_capitalize_hexa(int nb)
{
  int	res;

  if (nb >= 16)
    {
      res = nb % 16;
      nb = nb / 16;
      my_hexa(nb);
    }
  else if (nb > 0)
    {
      res = nb % 16;
      nb = nb / 16;
    }
  if (res > 9)
    my_putchar(res + 55);
  else
    my_putchar(res + 48);
}
