/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:20:00 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/02/08 03:58:14 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_message(char *message, t_cmd *cmd)
{
	close_command(cmd);
	write(2, message, ft_strlen(message));
	exit(1);
}

void	child_free(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd == NULL)
		return ;
	if (cmd->args)
	{
		while (cmd->args[i])
			free(cmd->args[i++]);
		free(cmd->args);
	}
	i = 0;
	if (cmd->cmd_path)
	{
		while (cmd->cmd_path[i])
			free(cmd->cmd_path[i++]);
		free(cmd->cmd_path);
	}
}

void	parent_free(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd == NULL)
		return ;
	if (cmd->fd1 >= 0)
		close(cmd->fd1);
	if (cmd->fd2 >= 0)
		close(cmd->fd2);
	if (cmd->cmd_path)
	{
		while (cmd->cmd_path[i])
			free(cmd->cmd_path[i++]);
		free(cmd->cmd_path);
	}
}

void	close_command(t_cmd *cmd)
{
	if (cmd == NULL)
		return ;
	if (cmd->fd1 >= 0)
		close(cmd->fd1);
	if (cmd->fd2 >= 0)
		close(cmd->fd2);
	if (cmd->tube[0] >= 0)
		close(cmd->tube[0]);
	if (cmd->tube[1] >= 0)
		close(cmd->tube[1]);
}

void	error_process(char *massage, t_cmd *cmd)
{
	close_command(cmd);
	error_message(massage, cmd);
}
