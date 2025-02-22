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

int	it_is_builtin(char *input, t_shell *shell)
{
	if (ft_strncmp(input, "cd", 2) == 0)
		return(ft_cd(input, shell));
	else if (ft_strncmp(input, "env", 3) == 0)
		return (print_env(shell->env));
	else if (ft_strncmp(input, "export", 6) == 0)
	{
		//ft_export(input, shell);
		return (1);
	}
	else if (ft_strncmp(input, "unset", 5) == 0)
	{
		//ft_unset(input, shell);
		return (1);
	}
	else if (ft_strncmp(input, "exit", 4) == 0)
	{
		//ft_exit(input, shell);
		return (1);
	}
	else if (ft_strncmp(input, "pwd", 3) == 0)
	{
		//ft_pwd(input, shell);
		return (1);
	}
	else if (ft_strncmp(input, "echo", 4) == 0)
	{
		//ft_echo(input, shell);
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

int	ft_cd(char *input, t_shell *shell)
{
	char	*path;
	char	*oldpwd;

	path = ft_strtrim(input + 2, " ");
	if (!path)
	{
		path = get_env_value("HOME", shell->env);
		if (!path)
		{
			ft_putstr_fd("cd: HOME not set\n", 2);
			return (1);
		}
	}
	oldpwd = getcwd(NULL, 0);
	if (chdir(path) == -1)
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
	}
	else
	{
		set_env_value("OLDPWD", oldpwd, shell->env);
		set_env_value("PWD", getcwd(NULL, 0), shell->env);
	}
	free(path);
	free(oldpwd);
	return(1);
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

