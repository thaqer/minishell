/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:24:16 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/03/22 15:21:14 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_command(char *input, t_shell *shell)
{
	int		status;
	char	*temp;

	temp = get_path(env_list_to_array(shell->env), NULL);
	shell->paths = ft_split(temp, ':');
	shell->args = ft_split(input, ' ');
	shell->command = get_command(shell->paths, shell->args[0]);
	if (!shell->command)
	{
		shell_error_message(strerror(errno));
		ft_free_array(shell->paths);
		ft_free_array(shell->args);
		return ;
	}
	shell->pid = fork();
	if (shell->pid == 0)
	{
		shell->env_array = env_list_to_array(shell->env);
		execve(shell->command, shell->args, shell->env_array);
		shell_error_message(strerror(errno));
		exit(EXIT_FAILURE);
	}
	else if (shell->pid < 0)
		shell_error_message(strerror(errno));
	else
		waitpid(shell->pid, &status, 0);
	free(shell->command);
}

char	*get_path(char **env, t_shell *shell)
{
	int	i;

	i = 0;
	(void)shell;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
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
