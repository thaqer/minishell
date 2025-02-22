/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:12:42 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/02/08 04:02:09 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../pipex/pipex.h"

# define PROMPT "darkspace$ "
# define MAX_PATH 4096

typedef struct s_env
{
        char	*value;
        struct s_env *next;
}	t_env;

typedef struct s_shell
{
        t_env        *env;
        
}        t_shell;

t_env	*get_env(char **env);
void    print_env(t_env *env);
void    execute_command(char *input, t_shell *shell);
void    ft_free_array(char **split);
void    handle_signal(int sig);
void    setup_signals(void);

#endif