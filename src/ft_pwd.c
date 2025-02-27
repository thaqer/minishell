/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:27:49 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/02/26 20:54:39 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void	ft_pwd(char *input, t_shell *shell)
{
	char	*pwd;

	(void)input;
	pwd = get_env_value("PWD", shell->env);
	if (!pwd)
	{
		pwd = getcwd(NULL, 0);
		if (!pwd)
		{
			shell_error_message(strerror(errno));
			return ;
		}
	}
	ft_putstr_fd(pwd, 1);
	ft_putstr_fd("\n", 1);
}

