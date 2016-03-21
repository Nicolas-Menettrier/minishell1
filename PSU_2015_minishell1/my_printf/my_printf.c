/*
** my_printf.c for my_printf in /home/menett_a/rendu/my_printf
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Tue Nov  3 20:42:12 2015 Nicolas Menettrier
** Last update Wed Jan 20 15:14:20 2016 menett_a
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "proto.h"
#include "struct.h"


int	flags(char c)
{
  if (c == 'd' || c == 'i' || c == 's' || c == 'u' || c == 'x' || c == 'X'
      || c == 'o' || c == '%' || c == 'p' || c == 'S' || c == 'c')
    return (1);
  return (0);
}

void	initialize_ptr(void (**ptr)())
{
  ptr[0] = my_put_nbr;
  ptr[1] = my_put_nbr;
  ptr[2] = my_putstr;
  ptr[4] = my_put_unsigned_nb;
  ptr[5] = my_hexa;
  ptr[6] = my_capitalize_hexa;
  ptr[7] = my_octal;
  ptr[8] = my_binary;
  ptr[9] = address;
  ptr[10] = my_put_octal;
}

int	my_call_ptr(char c, void (**ptr)(),
		    va_list argptr)
{
  char *flags;
  int	j;

  j = 0;
  flags = "discuxXobpS";
  if (c == '%')
    my_putchar('%');
  else if (c == 'c')
    my_putchar(va_arg(argptr, int));
  else
    {
      while (flags[j] != c)
	j = j + 1;
      ptr[j](va_arg(argptr, void *));
    }
}

void	init_struct(t_param *norm, char *str)
{
  norm->i = 0;
  norm->error = 0;
  while (str[norm->i] != '\0')
    norm->i = norm->i + 1;
  norm->i = norm->i - 1;
  while (str[norm->i] == ' ' && norm->i != 0 || str[norm->i] == '%')
    {
      if (str[norm->i] == '%')
	norm->error = 1;
      norm->i = norm->i - 1;
    }
  norm->i = 0;
}

int		my_printf(char *str, ...)
{
  t_param	norm;

  if (str == 0)
    return (-1);
  init_struct(&norm, str);
  va_start(norm.argptr, str);
  initialize_ptr(norm.ptr);
  while (str[norm.i] != '\0')
    {
      if (str[norm.i] == '%' && flags(str[norm.i + 1]) == 1)
	{
	  my_call_ptr(str[norm.i + 1], norm.ptr, norm.argptr);
	  norm.i = norm.i + 1;
	}
      else
	my_putchar(str[norm.i]);
      norm.i = norm.i + 1;
    }
  va_end(norm.argptr);
  if (norm.error == 1)
    return (-1);
  return (0);
}
