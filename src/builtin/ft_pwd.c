/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:27:49 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/04/06 00:39:07 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_pwd(t_shell *shell)
{
	char	*pwd;

	(void)shell;
	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		shell_error_message(strerror(errno));
		return (1);
	}
	ft_putstr_fd(pwd, 1);
	ft_putstr_fd("\n", 1);
	return (1);
}
