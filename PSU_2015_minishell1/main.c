/*
** main.c for main in /home/menet/Bootstrap/PSU_2015_minishell1
**
** Made by menett_a
** Login   <menett_a@epitech.net>
**
** Started on  Mon Jan 18 16:48:20 2016 menett_a
** Last update Sun Jan 24 23:39:08 2016 menett_a
*/

#include "proto_mini.h"

int	main(int argc, char **argv, char **env)
{
  int	err;

  err = 0;
  argc = argc;
  argv = argv;
  env = env;
  err = minishell(env);
  return (err);
}
