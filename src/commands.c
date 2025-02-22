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

int	handle_builtin_commands(char **args)
{
		char cwd[MAX_PATH];
	int			i;
	HIST_ENTRY	**history_entries;
	int			i;

	if (ft_strncmp(args[0], "cd", 2) == 0)
	{
		if (args[1])
		{
			if (chdir(args[1]) != 0)
				perror("cd");
		}
		else
			ft_putstr_fd("cd: missing argument\n", 2);
		return (1);
	}
	else if (ft_strncmp(args[0], "pwd", 3) == 0)
	{
		if (getcwd(cwd, sizeof(cwd)) != NULL)
			ft_putstr_fd(cwd, 1);
		else
			perror("getcwd");
		ft_putstr_fd("\n", 1);
		return (1);
	}
	else if (ft_strncmp(args[0], "echo", 4) == 0)
	{
		i = 1;
		while (args[i])
		{
			ft_putstr_fd(args[i], 1);
			if (args[i + 1])
				ft_putstr_fd(" ", 1);
			i++;
		}
		ft_putstr_fd("\n", 1);
		return (1);
	}
	else if (ft_strncmp(args[0], "history", 7) == 0)
	{
		history_entries = history_list();
		if (history_entries)
		{
			i = 0;
			while (history_entries[i])
			{
				ft_putstr_fd(history_entries[i]->line, 1);
				ft_putstr_fd("\n", 1);
				i++;
			}
		}
		return (1);
	}
	return (0);
}

void	execute_command(char *input, t_shell *shell)
{
	char	**args;
	pid_t	pid;

	(void)shell;
	args = ft_split(input, ' ');
	if (!args || !args[0])
		return ;
	if (handle_builtin_commands(args))
	{
		ft_free_array(args);
		return ;
	}
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
