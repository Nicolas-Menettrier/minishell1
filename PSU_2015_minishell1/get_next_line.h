/*
** get_next_line.h for get_next_line in /home/menett_a/Modules/CprogElem/Get_next_line
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Mon Jan  4 14:55:36 2016 Nicolas Menettrier
** Last update Mon Jan 18 11:34:52 2016 menett_a
*/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef READ_SIZE
#  define READ_SIZE (2)
# endif /* !READ_SIZE */

char	*get_next_line(const int fd);

typedef struct	s_gnl
{
  char		*str;
  int		size;
}		t_gnl;

#endif /* !GET_NEXT_LINE_H */
