/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:42:26 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/02/09 20:40:36 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_files(t_cmd *cmd, char **argv)
{
	cmd->fd[0] = open(argv[1], O_RDONLY);
	if (cmd->fd[0] == -1)
		perror("Error");
	cmd->fd[1] = open(argv[cmd->cmd_count + 2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (cmd->fd[1] == -1)
		perror("Error");
}

void	init_cmd(t_cmd *cmd, int argc)
{
	int i;

	cmd->cmd_count = argc - 3;
	cmd->pid = malloc(sizeof(pid_t) * cmd->cmd_count);
	cmd->cmds = malloc(sizeof(char *) * cmd->cmd_count);
	cmd->args = malloc(sizeof(char **) * cmd->cmd_count);
	cmd->fd = malloc(sizeof(int) * 2);
	cmd->tubes = malloc(sizeof(int *) * (cmd->cmd_count - 1));
	for (i = 0; i < cmd->cmd_count - 1; i++)
		cmd->tubes[i] = malloc(sizeof(int) * 2);
}

void	create_pipes(t_cmd *cmd)
{
	int i;

	for (i = 0; i < cmd->cmd_count - 1; i++)
	{
		if (pipe(cmd->tubes[i]) == -1)
			error_process("Error: Pipe failed", cmd);
	}
}

void	create_children(t_cmd *cmd, char **env)
{
	int i;

	for (i = 0; i < cmd->cmd_count; i++)
	{
		cmd->pid[i] = fork();
		if (cmd->pid[i] < 0)
			error_message("Fork failed\n", cmd);
		if (cmd->pid[i] == 0)
			child_process(cmd, i, env);
	}
}

void	child_process(t_cmd *cmd, int i, char **env)
{
	if (i == 0)
	{
		dup2(cmd->fd[0], STDIN_FILENO);
		dup2(cmd->tubes[i][1], STDOUT_FILENO);
	}
	else if (i == cmd->cmd_count - 1)
	{
		dup2(cmd->tubes[i - 1][0], STDIN_FILENO);
		dup2(cmd->fd[1], STDOUT_FILENO);
	}
	else
	{
		dup2(cmd->tubes[i - 1][0], STDIN_FILENO);
		dup2(cmd->tubes[i][1], STDOUT_FILENO);
	}
	close_pipes(cmd);
	cmd->args[i] = ft_split(cmd->cmds[i], ' ');
	if (!cmd->args[i])
		error_message("Error: Command arguments allocation failed\n", cmd);
	char *cmd_path = get_command(cmd->cmd_path, cmd->args[i][0]);
	if (cmd_path == NULL)
		error_message("Error: Command not found\n", cmd);
	if (execve(cmd_path, cmd->args[i], env) == -1)
	{
		child_free(cmd);
		perror("execve failed");
		exit(1);
	}
}

void	close_pipes(t_cmd *cmd)
{
	int i;

	for (i = 0; i < cmd->cmd_count - 1; i++)
	{
		close(cmd->tubes[i][0]);
		close(cmd->tubes[i][1]);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_cmd	cmd;

	if (argc < 5)
		error_message("Error: Wrong number of arguments\n", &cmd);
	init_cmd(&cmd, argc);
	open_files(&cmd, argv);
	create_pipes(&cmd);
	cmd.paths = get_path(env, &cmd);
	if (!cmd.paths)
		error_process("Error: PATH not found in environment variables\n", &cmd);
	cmd.cmd_path = ft_split(cmd.paths, ':');
	if (!cmd.cmd_path)
		error_process("Error: Command path allocation failed\n", &cmd);
	for (int i = 0; i < cmd.cmd_count; i++)
		cmd.cmds[i] = argv[i + 2];
	create_children(&cmd, env);
	close_pipes(&cmd);
	for (int i = 0; i < cmd.cmd_count; i++)
		waitpid(cmd.pid[i], NULL, 0);
	parent_free(&cmd);
}
