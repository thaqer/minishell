/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:24:16 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/02/09 23:23:10 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_command(char *input, t_shell *shell)
{
	char	**args;
	pid_t	pid;

	(void)shell;
	args = ft_split(input, ' ');
	if (!args || !args[0])
		return ;
	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
			perror("execvp");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("fork");
	else
		waitpid(pid, NULL, 0);
	ft_free_array(args);
}
