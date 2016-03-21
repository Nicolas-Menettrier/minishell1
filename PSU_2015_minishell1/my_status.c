/*
** my_status.c for statu in /home/menet/Modules/UnixSystemProgramming/PSU_2015_minishell1
**
** Made by menett_a
** Login   <menett_a@epitech.net>
**
** Started on  Sun Jan 24 22:02:17 2016 menett_a
** Last update Sun Jan 24 23:45:07 2016 menett_a
*/

#include <sys/types.h>
#include <sys/wait.h>
#include "proto_mini.h"

void	my_status(int status)
{
  if (WIFSIGNALED(status) == 1)
    {
      if (WTERMSIG(status) == 11)
	my_printf("Segmentation fault (core dumped)\n");
      else if (WTERMSIG(status) == 8)
	my_printf("floating point exception\n");
    }
}
