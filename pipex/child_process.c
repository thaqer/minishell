/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:44:17 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/02/09 20:40:36 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_child1(t_cmd *cmd, char **argv, char **env)
{
	cmd->pid[0] = fork();
	if (cmd->pid[0] < 0)
		error_message("Fork failed\n", cmd);
	if (cmd->pid[0] == 0)
		child1(cmd, argv, env);
}

void	create_child2(t_cmd *cmd, char **argv, char **env)
{
	cmd->pid[1] = fork();
	if (cmd->pid[1] == -1)
		error_message("Fork failed\n", cmd);
	if (cmd->pid[1] == 0)
		child2(cmd, argv, env);
}

void	child1(t_cmd *cmd, char **argv, char **env)
{
	dup2(cmd->tubes[0][1], STDOUT_FILENO);
	close(cmd->tubes[0][0]);
	dup2(cmd->fd[0], STDIN_FILENO);
	cmd->args[0] = ft_split(argv[2], ' ');
	if (!cmd->args[0])
	{
		child_free(cmd);
		error_message("Error: Command arguments allocation failed\n", cmd);
	}
	char *cmd_path = get_command(cmd->cmd_path, cmd->args[0][0]);
	if (cmd_path == NULL)
	{
		child_free(cmd);
		error_message("Error: Command_1 not found\n", cmd);
	}
	if (execve(cmd_path, cmd->args[0], env) == -1)
	{
		child_free(cmd);
		perror("execve failed");
		exit(1);
	}
}

void	child2(t_cmd *cmd, char **argv, char **env)
{
	dup2(cmd->tubes[0][0], STDIN_FILENO);
	close(cmd->tubes[0][1]);
	dup2(cmd->fd[1], STDOUT_FILENO);
	cmd->args[1] = ft_split(argv[3], ' ');
	if (!cmd->args[1])
	{
		child_free(cmd);
		error_message("Error: Command arguments allocation failed\n", cmd);
	}
	char *cmd_path = get_command(cmd->cmd_path, cmd->args[1][0]);
	if (cmd_path == NULL)
	{
		child_free(cmd);
		error_message("Error: Command_2 not found\n", cmd);
	}
	if (execve(cmd_path, cmd->args[1], env) == -1)
	{
		child_free(cmd);
		write(2, "execve failed\n", 14);
		exit(1);
	}
}
