/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:44:17 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/02/28 10:37:23 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_child1(t_cmd *cmd, char **argv, char **env)
{
	cmd->pid1 = fork();
	if (cmd->pid1 < 0)
		error_message("Fork failed\n", cmd);
	if (cmd->pid1 == 0)
		child1(cmd, argv, env);
}

void	create_child2(t_cmd *cmd, char **argv, char **env)
{
	cmd->pid2 = fork();
	if (cmd->pid2 == -1)
		error_message("Fork failed\n", cmd);
	if (cmd->pid2 == 0)
		child2(cmd, argv, env);
}

void	child1(t_cmd *cmd, char **argv, char **env)
{
	dup2(cmd->tube[1], STDOUT_FILENO);
	close(cmd->tube[0]);
	dup2(cmd->fd1, STDIN_FILENO);
	cmd->args = ft_split(argv[2], ' ');
	if (!cmd->args)
	{
		child_free(cmd);
		error_message("Error: Command arguments allocation failed\n", cmd);
	}
	cmd->cmd = get_command(cmd->cmd_path, cmd->args[0]);
	if (cmd->cmd == NULL)
	{
		child_free(cmd);
		error_message("Error: Command_1 not found\n", cmd);
	}
	if (execve(cmd->cmd, cmd->args, env) == -1)
	{
		child_free(cmd);
		perror("execve failed");
		exit(1);
	}
}

void	child2(t_cmd *cmd, char **argv, char **env)
{
	dup2(cmd->tube[0], STDIN_FILENO);
	close(cmd->tube[1]);
	dup2(cmd->fd2, STDOUT_FILENO);
	cmd->args = ft_split(argv[3], ' ');
	if (!cmd->args)
	{
		child_free(cmd);
		error_message("Error: Command arguments allocation failed\n", cmd);
	}
	cmd->cmd = get_command(cmd->cmd_path, cmd->args[0]);
	if (cmd->cmd == NULL)
	{
		child_free(cmd);
		error_message("Error: Command_2 not found\n", cmd);
	}
	if (execve(cmd->cmd, cmd->args, env) == -1)
	{
		child_free(cmd);
		write(2, "execve failed\n", 14);
		exit(1);
	}
}
