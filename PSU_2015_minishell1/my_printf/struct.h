/*
** struct.h for struct in /home/menett_a/rendu/my_printf
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Fri Nov  6 10:55:50 2015 Nicolas Menettrier
** Last update Wed Jan 20 15:08:42 2016 menett_a
*/

#ifndef STRUCT_H_
# define STRUCT_H_
# include <stdarg.h>

typedef	struct	s_param
{
  int		i;
  int		error;
  va_list	argptr;
  void		(*ptr[11])();
}		t_param;

#endif /* !STRUCT_H_ */
