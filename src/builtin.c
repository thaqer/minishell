/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:10:36 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/03/02 21:29:36 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	it_is_builtin(t_shell *shell)
{
	if (ft_strncmp(shell->input, "cd", 2) == 0)
		return (ft_cd(shell));
	else if (ft_strncmp(shell->input, "env", 3) == 0)
		return (print_env(shell->env));
	else if (ft_strncmp(shell->input, "export", 6) == 0)
		return (ft_export(shell->input, shell));
	else if (ft_strncmp(shell->input, "pwd", 3) == 0)
		return (ft_pwd(shell->input, shell));
	else if (ft_strncmp(shell->input, "exit", 4) == 0)
		return (ft_exit(shell->input, shell));
	else if (ft_strncmp(shell->input, "unset", 5) == 0)
	{
		// ft_unset(shell->input, shell);
		return (1);
	}
	else if (ft_strncmp(shell->input, "echo", 4) == 0)
	{
		// ft_echo(shell->input, shell);
		return (1);
	}
	else
		return (0);
}
