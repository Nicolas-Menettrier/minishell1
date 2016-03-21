/*
** realloc.c for realloc in /home/menett_a/Modules/CprogElem/Get_next_line
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Mon Jan  4 12:41:51 2016 Nicolas Menettrier
** Last update Sun Jan 24 16:32:43 2016 menett_a
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

void	init_buff(char *bu)
{
  int	i;

  i = 0;
  while (bu[i] != '\0' && i != READ_SIZE)
    {
      bu[i] = '\0';
      i = i + 1;
    }
}

int	my_strlend(char *str, int x)
{
  int	i;

  i = 0;
  if (x == 1)
    {
      while (str != NULL && str[i] != '\0')
	i = i + 1;
    }
  else if (str != NULL)
    {
      while (str[i] != '\n' && str[i] != '\0')
	i = i + 1;
      if (str[i] == '\n')
	return (0);
      else
	return (1);
    }
  return (i);
}

char	*my_realloc(char *cop, int size, char *bu, int *cpt)
{
  char	*tmp;
  int	i;

  i = 0;
  if ((tmp = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  while (cop[i] != '\0')
    {
      tmp[i] = cop[i];
      i = i + 1;
    }
  while (bu[*cpt] != '\0' && bu[*cpt] != '\n')
    {
      tmp[i] = bu[*cpt];
      *cpt = *cpt + 1;
      i = i + 1;
    }
  if (bu[*cpt] == '\0' || (bu[*cpt] == '\n' && bu[*cpt] == '\0'))
    *cpt = 0;
  else if (bu[*cpt] == '\n' && bu[*cpt] != '\0')
    *cpt = *cpt + 1;
  free(cop);
  tmp[i] = '\0';
  return (tmp);
}

char	*norme_malloc(t_gnl gl, char *bu, int *ct, int *size)
{
  if (*ct == 0)
    init_buff(bu);
  else if (*ct != 0)
    if ((gl.str = my_realloc(gl.str, my_strlend(gl.str, 1)
			     + *size + 1, bu, ct)) == NULL)
      return (NULL);
  if (my_strlend(gl.str, 2) == 0)
    return (gl.str);
  else if (*ct == 0)
    init_buff(bu);
  return (gl.str);
}

char		*get_next_line(int fd)
{
  static char	bu[READ_SIZE + 1];
  static int	ct;
  static int	size;
  t_gnl		gl;

  if ((gl.str = malloc(sizeof(char))) == NULL)
    return (NULL);
  gl.str[0] = '\0';
  if ((gl.str = norme_malloc(gl, bu, &ct, &size)) == NULL)
    return (NULL);
  while (my_strlend(bu, 2) != 0
	 && (size = read(fd, bu, READ_SIZE)) > 0)
    {
      bu[size] = '\0';
      if ((gl.str = my_realloc(gl.str, my_strlend(gl.str, 1)
			       + size + 1, bu, &ct)) == NULL)
	return (NULL);
    }
  if (gl.str[0] != '\0' || size > 0)
    return (gl.str);
  return (NULL);
}
