/*
** my_putchar.c for my_putchar in /home/menett_a/rendu/Piscine_C_J10/lib/my
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Sun Oct 11 21:22:44 2015 Nicolas Menettrier
** Last update Wed Jan 20 15:11:47 2016 menett_a
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
