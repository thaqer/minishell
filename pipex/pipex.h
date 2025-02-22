/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:43:02 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/02/09 20:40:36 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_cmd
{
	pid_t	*pid;
	char	**cmds;
	char	*paths;
	char	**cmd_path;
	char	***args;
	int		*fd;
	int		**tubes;
	int		cmd_count;
}			t_cmd;

void		error_message(char *message, t_cmd *cmd);
void		open_files(t_cmd *cmd, char **argv);
char		*get_path(char **env, t_cmd *cmd);
char		*get_command(char **path, char *cmd);
void		child_free(t_cmd *cmd);
void		create_child1(t_cmd *cmd, char **argv, char **env);
void		create_child2(t_cmd *cmd, char **argv, char **env);
void		child1(t_cmd *cmd, char **argv, char **env);
void		child2(t_cmd *cmd, char **argv, char **env);
void		parent_free(t_cmd *pipex);
void		close_command(t_cmd *cmd);
void		error_process(char *massage, t_cmd *cmd);
void		create_children(t_cmd *cmd, char **env);
void		child_process(t_cmd *cmd, int i, char **env);
void		close_pipes(t_cmd *cmd);

#endif