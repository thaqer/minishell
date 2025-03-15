/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:12:42 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/03/08 00:36:11 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <errno.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <dirent.h>
# include <fcntl.h>
# include <unistd.h>

# define PROMPT "\033[94mdarkspace\033[0m:~"
# define MAX_PATH 4096

typedef struct s_env
{
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_token
{
	char			*value;
	struct s_token	*next;
}					t_token;

typedef struct s_shell
{
	t_env			*env;
	t_token			*token;
	pid_t			pid;
	int				pip_num;
	char			*pwd;
	char			*input;
	char			**args;
	char			**paths;
	char			*path;
	char			*command;
	char			*full_path;
	int				exit_status;
}					t_shell;

// environment.c
t_env				*get_env(char **env);
int				print_env(t_env *env);
void				set_env_value(char *key, char *value, t_env *env);
char				*get_env_value(char *key, t_env *env);
int				list_size(t_env *env);

// builtin.c
int				it_is_builtin(t_shell *shell);

// ft_cd.c
int				ft_cd(t_shell *shell);
void				end_cd_process(t_shell *shell, char *oldpwd, char *pwd);

// ft_pwd.c
int				ft_pwd(t_shell *shell);

// ft_export.c
int				ft_export(char *input, t_shell *shell);
void				handle_value(char *value);
void				add_env(char *key, char *value, t_env *env);
void				veiled_key(char *key, t_shell *shell);
void	process_export(char **temp, t_shell *shell);

// ft_unset.c
int				ft_unset(char *input, t_shell *shell);

// expantion.c
int				expand_env(t_shell *shell, char *input, int i);

// ft_echo.c
int				ft_echo(char *input, t_shell *shell);
int				handle_quotations(t_shell *shell, char *input, int i);
int				single_quote(t_shell *shell, char *input, int i);
int				double_quote(t_shell *shell, char *input, int i);

// commands.c
void				execute_command(char *input, t_shell *shell);
char				*get_path(char **env, t_shell *shell);
char				*get_command(char **cmd_path, char *cmd);

// ft_exit.c
int				ft_exit(char *input, t_shell *shell);
void				ft_free_array(char **split);
void				free_env(t_env *env);

// signals.c
void				handle_signal(int sig);
void				setup_signals(void);

// tokenizer.c
void				tokenization(char *input, t_shell *shell);
int				handle_spscial_char(char *input, int x, t_shell *shell);
int				handle_pipe(char *input, int x, t_shell *shell);
void				print_token(t_shell *shell);

// utils.c
char				**env_list_to_array(t_env *env);
int				shell_error_message(char *message);
void				veiled_key(char *key, t_shell *shell);

#endif