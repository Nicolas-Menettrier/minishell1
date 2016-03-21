/*
** minishell.c for minishell in /home/menet/Modules/UnixSystemProgramming/PSU_2015_minishell1
**
** Made by menett_a
** Login   <menett_a@epitech.net>
**
** Started on  Thu Jan 21 16:41:51 2016 menett_a
** Last update Sun Jan 24 23:31:43 2016 menett_a
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "proto_mini.h"
#include "get_next_line.h"

int	is_path(char *str)
{
  char	*path;
  int	i;

  i = 0;
  path = "PATH=";
  while (str != NULL && path[i] != '\0' && path[i] == str[i]
	 && str[i] != '\0')
    i = i + 1;
  if (path[i] == '\0')
    return (0);
  return (1);
}

int	my_execve(char **opt, char **env)
{
  char	**path;
  char	*str;
  int	i;

  i = 0;
  if (opt[0][0] != '/' && opt[0][0] != '.')
    {
      if (my_test(env, opt, &i) == -1)
	return (-1);
      path = str_to_word(&env[i][5], ':');
      i = 0;
      while (path[i] != NULL)
	{
	  str = path_file(path[i], opt[0]);
	  execve(str, opt, env);
	  i = i + 1;
	}
    }
  else
    execve(opt[0], opt, env);
  return (-1);
}

int	is_cmd(char **opt, int *ex, char ***env)
{
  char	*cd;
  char	*exit;
  char	*setenv;
  char	*unsetenv;

  cd = "cd";
  exit = "exit";
  setenv = "setenv";
  unsetenv = "unsetenv";
  if (opt == NULL)
    return (1);
  if (opt[0][0] == cd[0] && opt[0][1] == cd[1] && opt[0][2] == '\0')
    return (my_cd(opt[1], env));
  if (my_strcmp(opt[0], exit) == 1)
    return (my_exit(ex, opt));
  if (my_strcmp(opt[0], setenv) == 1)
    return (my_setenv(opt, env));
  if (my_strcmp(opt[0], unsetenv) == 1)
    return (my_unsetenv(opt, env));
  return (0);
}

void	exec_arg(char **opt, char **env)
{
  pid_t	pid;
  int	status;

  pid = fork();
  if (pid == 0)
    {
      if (my_execve(opt, env) == -1)
	{
	  my_printf("bash: %s: Aucun fichier ou dossier de ce type\n", opt[0]);
	  my_free(opt);
	  exit(0);
	}
    }
  else
    {
      wait(&status);
      my_status(status);
      my_free(opt);
    }
}

int	minishell(char **env)
{
  char	*str;
  int	exit;
  int	i;

  i = 1;
  exit = -6;
  env = stock_env(env, 0, NULL, NULL);
  while (exit == -6)
    {
      my_printf("[<%d>%s]$ ", i, "menett_a");
      if ((str = get_next_line(0)) == NULL)
	exit = 0;
      if (exit <= -6 && str[0] == '\0');
      else if (exit <= -6 && is_cmd(str_to_word(str, ' '), &exit, &env) == 0)
	exec_arg(str_to_word(str, ' '), env);
      i = i + 1;
      free(str);
    }
  my_free(env);
  my_printf("exit\n");
  return (exit);
}
