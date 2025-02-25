/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:24:16 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/02/25 13:39:00 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_command(char *input, t_shell *shell)
{
	char	**args;
	pid_t	pid;
	char	*full_path;
	char	**env_array;

	args = ft_split(input, ' ');
	if (!args || !args[0])
		return ;
	full_path = args[0]; // Assuming the command is in the PATH
	env_array = env_list_to_array(shell->env);
	if (!env_array)
	{
		ft_free_array(args);
		return ;
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(full_path, args, env_array) == -1)
			perror("\033[31mexecve\033[0m");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("\033[31mfork\033[0m");
	else
		waitpid(pid, NULL, 0);
	ft_free_array(args);
	ft_free_array(env_array);
}
