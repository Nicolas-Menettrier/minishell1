/*
** my_strcmp.c for my_strcmp in /home/menett_a/rendu/Piscine_C_J06/ex_06
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Mon Oct  5 18:28:47 2015 Nicolas Menettrier
** Last update Fri Jan 22 17:30:19 2016 menett_a
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
    i = i + 1;
  if (s1[i] == '\0' && s2[i] == '\0')
    return (1);
  return (0);
}

int	my_strcmp_equal(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '=' &&
	 s2[i] != '\0')
    i = i + 1;
  if (s1[i] == '\0' && s2[i] == '=')
    return (1);
  return (0);
}
