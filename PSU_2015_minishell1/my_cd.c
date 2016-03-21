/*
** cd.c for cd in /home/menet/Modules/UnixSystemProgramming/PSU_2015_minishell1
**
** Made by menett_a
** Login   <menett_a@epitech.net>
**
** Started on  Sun Jan 24 20:37:36 2016 menett_a
** Last update Sun Jan 24 22:20:10 2016 menett_a
*/

#include <unistd.h>
#include "proto_mini.h"

int	my_cd(char *path, char ***env)
{

  if (chdir(path) < 0)
    my_printf("%s: is not a file\n", path);
  else
    *env = can_i_replace(getcwd(NULL, 0), *env, "PWD");
  return (1);
}
