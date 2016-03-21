/*
** proto_mini.h for protooooo in /home/menet/Bootstrap/PSU_2015_minishell1
**
** Made by menett_a
** Login   <menett_a@epitech.net>
**
** Started on  Wed Jan 20 15:17:57 2016 menett_a
** Last update Sun Jan 24 23:35:26 2016 menett_a
*/

#ifndef PROTO_MINI_H_
# define PROTO_MINI_H_

#include "struct.h"

char	**replace_this(char **, char *, char *, int *);
char	**my_stock(char *, t_word, char **, char);
char	**copy_line(char **, int, char *, char *);
char	**stock_env(char **, int, char *, char *);
char	**new_line(char *, char **, char *, int);
char	**can_i_replace(char *, char **, char *);
char	**copy_env_unset(char **, char **, int);
char	**my_unset(char **, int);
char	**norme_stock(char **, char **);
char	**can_i_remove(char **, char *);
char	**str_to_word(char *, char);
char	*copy_str(char *, char *, int *);
char	*size_word(char *, int, char);
char	*path_file(char *, char *);
char	*copy_norm(char *, char *);
char	*epur_word(char *);
void	exec_arg(char **, char **);
void	my_free(char **);
void	my_status(int);
int	is_cmd(char **, int *, char ***);
int	my_test(char **, char **, int *);
int	init_word(t_word, char *, char);
int	my_strcmp_equal(char *, char *);
int	my_unsetenv(char **, char ***);
int	calcul(int, int, char *, int);
int	my_setenv(char **, char ***);
int	int_nbr(char, int, int, int);
int	my_execve(char **, char **);
int	my_strcmp(char *, char *);
int	my_exit(int *, char **);
int	my_cd(char *, char ***);
int	my_printf(char *, ...);
int	number(char *, int);
int	my_get_nbr(char *);
int	minishell(char **);
int	my_strlen(char *);
int	is_path(char *);

#endif /* !PROTO_MINI_H_ */
