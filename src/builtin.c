/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-22 14:10:36 by tbaniatt          #+#    #+#             */
/*   Updated: 2025-02-22 14:10:36 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

int	it_is_builtin(t_shell *shell)
{
	if (ft_strncmp(shell->input, "cd", 2) == 0)
		return(ft_cd(shell->input, shell));
	else if (ft_strncmp(shell->input, "env", 3) == 0)
		return (print_env(shell->env));
	else if (ft_strncmp(shell->input, "export", 6) == 0)
	{
		//ft_export(shell->input, shell);
		return (1);
	}
	else if (ft_strncmp(shell->input, "unset", 5) == 0)
	{
		//ft_unset(shell->input, shell);
		return (1);
	}
	else if (ft_strncmp(shell->input, "exit", 4) == 0)
	{
		//ft_exit(shell->input, shell);
		return (1);
	}
	else if (ft_strncmp(shell->input, "pwd", 3) == 0)
	{
		//ft_pwd(shell->input, shell);
		return (1);
	}
	else if (ft_strncmp(shell->input, "echo", 4) == 0)
	{
		//ft_echo(shell->input, shell);
		return (1);
	}
	return (0);
}

int	print_env(t_env *env)
{
	while (env)
	{
		ft_putstr_fd(env->value, 1);
		ft_putstr_fd("\n", 1);
		env = env->next;
	}
	return (1);
}

int	ft_cd(t_shell *shell)
{
	char	*path;
	char	*oldpwd;
	char	*pwd;

	path = ft_strtrim(shell->input + 2, " ");
	if (!path)
	{
		path = get_env_value("HOME", shell->env);
		if (!path)
			return (error_message("HOME not set"));
	}
	oldpwd = getcwd(NULL, 0);
	if (!oldpwd)
		return (error_message(strerror(errno)));
	if (chdir(path) == -1)
	{
		free(oldpwd);
		return (error_message(strerror(errno)));
	}
	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (error_message(strerror(errno)));
	set_env_value("OLDPWD", oldpwd, shell->env);
	set_env_value("PWD", pwd, shell->env);
	free(oldpwd);
	free(pwd);
	return (1);
}

int	error_message(char *message)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

char	*get_env_value(char *key, t_env *env)
{
	size_t	key_len;

	key_len = ft_strlen(key);
	while (env)
	{
		if (ft_strncmp(env->value, key, key_len) == 0 && env->value[key_len] == '=')
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
		if (ft_strncmp(env->value, key, key_len) == 0 && env->value[key_len] == '=')
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

