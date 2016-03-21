/*
** my_str_to_word.c for str_mini in /home/menet/Bootstrap/PSU_2015_minishell1
**
** Made by menett_a
** Login   <menett_a@epitech.net>
**
** Started on  Tue Jan 19 14:36:50 2016 menett_a
** Last update Sun Jan 24 22:40:36 2016 menett_a
*/

#include <stdlib.h>
#include "proto_mini.h"
#include "struct.h"

char	*size_word(char *str, int i, char c)
{
  char	*stv;
  int	j;

  j = i;
  while (str[i] != c && str[i] != '\0')
    i = i + 1;
  if ((stv = malloc(sizeof(char) * (i - j + 1))) == NULL)
    return (NULL);
  return (stv);
}

char	**my_stock(char *str, t_word wo, char **word, char c)
{
  wo.i = 0;
  wo.k = 0;
  while (str[wo.i] != '\0')
    {
      if ((word[wo.k] = size_word(str, wo.i, c)) == NULL)
	return (NULL);
      wo.j = 0;
      while (str[wo.i] != c && str[wo.i] != '\0')
	{
	  word[wo.k][wo.j] = str[wo.i];
	  wo.i = wo.i + 1;
	  wo.j = wo.j + 1;
	}
      word[wo.k][wo.j] = '\0';
      if (str[wo.i] != '\0')
	wo.i = wo.i + 1;
      wo.k = wo.k + 1;
    }
  word[wo.k] = NULL;
  return (word);
}

char	*epur_word(char *str)
{
  char	*stv;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((stv = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
    i = i + 1;
  while (str[i] != '\0')
    {
      if ((str[i] == ' ' || str[i] == '\t')
	  && (str[i + 1] == ' ' || str[i + 1] == '\0' || str[i + 1] == '\t'));
      else
	{
	  stv[j] = str[i];
	  j = j + 1;
	}
      i = i + 1;
    }
  stv[j] = '\0';
  return (stv);
}

int	init_word(t_word word, char *str, char c)
{
  int	i;

  i = 0;
  if (str[0] == '\0')
    return (0);
  while (str[i] != '\0')
    {
      if (str[i] == c)
	word.nb_word = word.nb_word + 1;
      i = i + 1;
    }
  return (word.nb_word);
}

char		**str_to_word(char *str, char c)
{
  char		**stv;
  t_word	word;

  word.nb_word = 1;
  str = epur_word(str);
  word.nb_word = init_word(word, str, c);
  if (word.nb_word == 0)
    return (NULL);
  if ((stv = malloc(sizeof(char *) * (word.nb_word + 1))) == NULL)
    return (NULL);
  stv = my_stock(str, word, stv, c);
  return (stv);
}
