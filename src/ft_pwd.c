/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:27:49 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/03/01 16:06:56 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// re move lines 20-22 and line 30
int	ft_pwd(t_shell *shell)
{
	char	*pwd;

	// pwd = get_env_value("PWD", shell->env);
	// if (!pwd)
	// {
	(void)shell;
	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		shell_error_message(strerror(errno));
		return (1);
	}
	// }
	ft_putstr_fd(pwd, 1);
	ft_putstr_fd("\n", 1);
	return (1);
}
