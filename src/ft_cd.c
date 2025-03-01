/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:25:45 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/02/26 20:15:05 by tbaniatt         ###   ########.fr       */
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
		return (shell_error_message(strerror(errno)));
	if (chdir(path) == -1)
	{
		free(oldpwd);
		return (shell_error_message(strerror(errno)));
	}
	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (shell_error_message(strerror(errno)));
	end_cd_process(shell, oldpwd, pwd);
	return (1);
}

void	end_cd_process(t_shell *shell, char *oldpwd, char *pwd)
{
	set_env_value("OLDPWD", oldpwd, shell->env);
	set_env_value("PWD", pwd, shell->env);
	free(oldpwd);
	free(pwd);
}

char	*get_env_value(char *key, t_env *env)
{
	size_t	key_len;

	key_len = ft_strlen(key);
	while (env)
	{
		if (ft_strncmp(env->value, key, key_len) == 0
			&& env->value[key_len] == '=')
		{
			return (ft_strdup(env->value + key_len + 1));
		}
		env = env->next;
	}
	return (NULL);
}

void	set_env_value(char *key, char *value, t_env *env)
{
	size_t	key_len;
	char	*new_value;
	t_env	*tmp;

	key_len = ft_strlen(key);
	new_value = ft_strjoin(key, "=");
	new_value = ft_strjoin(new_value, value);
	while (env)
	{
		if (ft_strncmp(env->value, key, key_len) == 0
			&& env->value[key_len] == '=')
		{
			free(env->value);
			env->value = new_value;
			return ;
		}
		if (!env->next)
			break ;
		env = env->next;
	}
	tmp = malloc(sizeof(t_env));
	if (!tmp)
		return ;
	tmp->value = new_value;
	tmp->next = NULL;
	env->next = tmp;
}

int	shell_error_message(char *message)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}
