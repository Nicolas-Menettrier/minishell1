/*
** my_path_copy.c for path in /home/menet/Modules/UnixSystemProgramming/PSU_2015_minishell1
**
** Made by menett_a
** Login   <menett_a@epitech.net>
**
** Started on  Thu Jan 21 17:06:41 2016 menett_a
** Last update Sun Jan 24 21:50:04 2016 menett_a
*/

#include <stdlib.h>
#include "proto_mini.h"

char	*path_file(char *p, char *c)
{
  char	*str;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((str = malloc(sizeof(char) * (my_strlen(p) + my_strlen(c) + 2))) == NULL)
    exit(1);
  while (p[i] != '\0')
    {
      str[j] = p[i];
      i = i + 1;
      j = j + 1;
    }
  str[j] = '/';
  j = j + 1;
  i = 0;
  while (c[i] != '\0')
    {
      str[j] = c[i];
      i = i + 1;
      j = j + 1;
    }
  str[j] = '\0';
  return (str);
}
