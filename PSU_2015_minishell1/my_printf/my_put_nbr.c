/*
** my_put_nbr.c for my_put_nbr in /home/menett_a/rendu/Piscine_C_J03
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Wed Sep 30 22:00:45 2015 Nicolas Menettrier
** Last update Tue Jan 19 13:45:53 2016 menett_a
*/

#include "proto.h"

void	limit_int()
{
  my_putchar('-');
  my_putchar('2');
  my_putchar('1');
  my_putchar('4');
  my_putchar('7');
  my_putchar('4');
  my_putchar('8');
  my_putchar('3');
  my_putchar('6');
  my_putchar('4');
  my_putchar('8');
}

void	my_put_nbr(int nb)
{
  int	nbf;

  if (nb == -2147483648)
    limit_int(nb);
  else if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
      my_put_nbr(nb);
    }
  else if (nb >= 10)
    {
      nbf = nb % 10;
      nb = nb / 10;
      my_put_nbr(nb);
      my_putchar(nbf + 48);
    }
  else
    my_putchar(nb + 48);
}
