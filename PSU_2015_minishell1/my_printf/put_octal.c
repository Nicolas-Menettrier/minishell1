/*
** put_octal.c for put_octal in /home/menett_a/rendu/my_printf
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Thu Nov 12 21:15:34 2015 Nicolas Menettrier
** Last update Tue Jan 19 13:46:16 2016 menett_a
*/

#include "proto.h"

void	my_calc_octal(int nb)
{
  int	tab[3];
  int	i;
  int	res;

  tab[0] = 0;
  tab[1] = 0;
  tab[2] = 0;
  i = 2;
  while (nb > 0)
    {
      res = nb % 8;
      nb = nb / 8;
      tab[i] = res;
      i = i - 1;
    }
  my_put_nbr(tab[0]);
  my_put_nbr(tab[1]);
  my_put_nbr(tab[2]);
}

void	my_put_octal(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 32 || str[i] >= 127)
	{
	  my_putstr("\\");
	  my_calc_octal(str[i]);
	  i = i + 1;
	}
      else
	{
	  my_putchar(str[i]);
	  i = i + 1;
	}
    }
}
