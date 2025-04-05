/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:25:45 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/03/22 17:26:11 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_cd(t_shell *shell)
{
	char	*path;
	char	*oldpwd;
	char	*pwd;

	path = ft_strtrim(shell->input + 2, " ");
	if (!path || ft_strlen(path) == 0 || ft_strncmp(path, "~", 1) == 0)
	{
		free(path);
		path = get_env_value("HOME", shell->env);
		if (!path)
			return (shell_error_message("HOME not set"));
	}
	oldpwd = getcwd(NULL, 0);
	if (!oldpwd)
	{
		free(path);
		return (shell_error_message(strerror(errno)));
	}
	if (chdir(path) == -1)
	{
		free(oldpwd);
		free(path);
		return (shell_error_message(strerror(errno)));
	}
	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		free(oldpwd);
		free(path);
		return (shell_error_message(strerror(errno)));
	}
	end_cd_process(shell, oldpwd, pwd);
	free(path);
	return (1);
}

void	end_cd_process(t_shell *shell, char *oldpwd, char *pwd)
{
	set_env_value("OLDPWD=", oldpwd, shell->env);
	set_env_value("PWD=", pwd, shell->env);
	free(oldpwd);
	free(pwd);
}
