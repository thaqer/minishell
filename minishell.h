/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:12:42 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/03/01 20:46:51 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "pipex/pipex.h"
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
# include <unistd.h>

# define PROMPT "\033[94mdarkspace$ \033[0m"
# define MAX_PATH 4096

typedef struct s_env
{
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_shell
{
	t_env			*env;
	char			*input;
	char			**args;
	char			**paths;
	char			*path;
	char			*command;
	char			*full_path;
	int				exit_status;
}					t_shell;

t_env				*get_env(char **env);
int					print_env(t_env *env);
void				execute_command(char *input, t_shell *shell);
void				ft_free_array(char **split);
void				handle_signal(int sig);
void				setup_signals(void);
int					it_is_builtin(t_shell *shell);
int					ft_cd(t_shell *shell);
int					print_env(t_env *env);
void				set_env_value(char *key, char *value, t_env *env);
char				*get_env_value(char *key, t_env *env);
int					shell_error_message(char *message);
int				ft_pwd(char *input, t_shell *shell);
char				**env_list_to_array(t_env *env);
void				end_cd_process(t_shell *shell, char *oldpwd, char *pwd);
int				ft_export(char *input, t_shell *shell);
void				add_env(char *key, char *value, t_env *env);
#endif