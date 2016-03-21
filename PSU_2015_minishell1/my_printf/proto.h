/*
** proto.h for proto in /home/menett_a/rendu/my_prvoidf
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Mon Nov  9 13:14:26 2015 Nicolas Menettrier
** Last update Wed Jan 20 15:12:03 2016 menett_a
*/

#ifndef PROTO_H_
# define PROTO_H_
# include "struct.h"

void	address(long long nb);
void	my_pourcent(void *);
void	my_put_nbr(int nb);
void	my_free(t_param *);
void	my_put_unsigned_nb(unsigned int nb);
void	my_putchar(char c);
void	my_hexa(int nb);
void	my_octal(int nb);
void	my_capitalize_hexa(int nb);
void	my_binary(int nb);
void	my_put_nbr(int nb);
void	my_putstr(char *str);
void	my_put_octal(char *str);
int	my_printf(char *str, ...);

#endif /* PROTO_H_ */
