/*
** capitalize_hexa.c for capitalize_hexa in /home/menett_a/rendu/my_printf
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Wed Nov 11 14:19:32 2015 Nicolas Menettrier
** Last update Tue Jan 19 13:45:23 2016 menett_a
*/

#include "proto.h"

void	my_hexa_add(long long nb)
{
  int	res;

  if (nb >= 16)
    {
      res = nb % 16;
      nb = nb / 16;
      my_hexa_add(nb);
    }
  else if (nb > 0)
    {
      res = nb % 16;
      nb = nb / 16;
    }
  if (res > 9)
    my_putchar(res + 87);
  else
    my_putchar(res + 48);
}

void	address(long long nb)
{
  if (nb == 0)
    my_putstr("(nil)");
  else
    {
      my_putstr("0x");
      my_hexa_add(nb);
    }
}
