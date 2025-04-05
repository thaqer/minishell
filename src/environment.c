/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:39:41 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/04/05 15:42:18 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*get_env(char **env)
{
	t_env	*env_list;
	t_env	*tmp;
	int		i;

	i = 0;
	env_list = NULL;
	while (env[i])
	{
		tmp = malloc(sizeof(t_env));
		if (!tmp)
			return (NULL);
		tmp->value = ft_strdup(env[i]);
		if (!tmp->value)
			return (NULL);
		tmp->next = 0;
		if (!env_list)
			env_list = tmp;
		else
		{
			tmp->next = env_list;
			env_list = tmp;
		}
		i++;
	}
	return (env_list);
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
	char	*tmp_value;

	key_len = ft_strlen(key);
	new_value = ft_strjoin(key, "=");
	if (value)
	{
		tmp_value = ft_strjoin(new_value, value);
		free(new_value);
		new_value = tmp_value;
	}
	while (env)
	{
		if (ft_strncmp(env->value, key, key_len) == 0)
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
