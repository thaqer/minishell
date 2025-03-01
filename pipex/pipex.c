/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:42:26 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/02/28 10:37:33 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_files(t_cmd *cmd, char **argv)
{
	cmd->fd1 = open(argv[1], O_RDONLY);
	if (cmd->fd1 == -1)
		perror("Error");
	cmd->fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (cmd->fd2 == -1)
		perror("Error");
}

char	*get_path(char **env, t_cmd *cmd)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	error_message("Error: PATH not found in environment variables\n", cmd);
	return (NULL);
}

char	*get_command(char **cmd_path, char *cmd)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	if (!cmd || !cmd_path)
		return (NULL);
	if (access(cmd, F_OK) == 0)
		return (ft_strdup(cmd));
	i = 0;
	while (cmd_path[i])
	{
		tmp = ft_strjoin(cmd_path[i], "/");
		tmp2 = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(tmp2, F_OK) == 0)
			return (tmp2);
		free(tmp2);
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv, char **env)
{
	t_cmd	cmd;
	int		p;

	cmd = (t_cmd){0};
	if (argc != 5)
		error_message("Error: Wrong number of arguments\n", &cmd);
	open_files(&cmd, argv);
	p = pipe(cmd.tube);
	if (p == -1)
		error_process("Error: Pipe failed", &cmd);
	cmd.paths = get_path(env, &cmd);
	if (!cmd.paths)
		error_process("Error: PATH not found in environment variables\n", &cmd);
	cmd.cmd_path = ft_split(cmd.paths, ':');
	if (!cmd.cmd_path)
		error_process("Error: Command path allocation failed\n", &cmd);
	if (cmd.fd1 > 0)
		create_child1(&cmd, argv, env);
	if (cmd.fd2 >= 0)
		create_child2(&cmd, argv, env);
	close_command(&cmd);
	waitpid(-1, NULL, 0);
	waitpid(-1, NULL, 0);
	parent_free(&cmd);
}
